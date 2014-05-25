#include "GameLayer.h"
#include "GameSprite.h"
#include "Rocket.h"
#include "LineContainer.h"

USING_NS_CC;

GameLayer::~GameLayer() {
}

Scene* GameLayer::createScene() {
    auto scene = Scene::create();
    
    auto layer = GameLayer::create();

    scene->addChild(layer);

    return scene;
}

bool GameLayer::init() {
    if ( !Layer::init() ) {
        return false;
    }

    _screenSize = Director::getInstance()->getWinSize();
    _state      = GameStates::INTRO;
    _running    = false;

    createGameScreen();
    createParticles();
    
    schedule(schedule_selector(GameLayer::update));

    return true;
}

void GameLayer::createGameScreen() {
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("sprite_sheet.plist", "sprite_sheet.png");
    _rocket = Rocket::create();
    _rocket->setPosition(Point{_screenSize.width * 0.5f, _screenSize.height * 0.1f});
    addChild(_rocket);

    _lineContainer = LineContainer::create();
    addChild(_lineContainer);
    
    // add planets
    GameSprite *planet = GameSprite::createWithFrameName("planet_1.png");
    planet->setPosition(Point{_screenSize.width * 0.25f, _screenSize.height * 0.8f});
    _planets.pushBack(planet);
    addChild(planet, kBackground, kSpritePlanet);
    
    planet = GameSprite::createWithFrameName("planet_2.png");
    planet->setPosition(Point{_screenSize.width * 0.8f, _screenSize.height * 0.45f});
    _planets.pushBack(planet);
    addChild(planet, kBackground, kSpritePlanet);
}

void GameLayer::createParticles() {
    _jet = ParticleSystemQuad::create("jet.plist");
    _jet->setSourcePosition(Point{-_rocket->getRadius() * 0.8f, 0});
    _jet->setAngle(180);
    _jet->setPosition(_rocket->getPosition());
    _jet->stopSystem();
    addChild(_jet, kBackground);
    
    _boom = ParticleSystemQuad::create("boom.plist");
    _boom->stopSystem();
    addChild(_boom, kForeground);
    
    _comet = ParticleSystemQuad::create("comet.plist");
    _comet->stopSystem();
    _comet->setPosition(Point{0, _screenSize.height * 0.6f});
    _comet->setVisible(false);
    addChild(_comet, kForeground);
    
    _pickup = ParticleSystemQuad::create("plink.plist");
    _pickup->stopSystem();
    addChild(_pickup, kMiddleground);
    
    _warp = ParticleSystemQuad::create("warp.plist");
    _warp->setPosition(_rocket->getPosition());
    addChild(_warp, kBackground);
    
    _star = ParticleSystemQuad::create("star.plist");
    _star->stopSystem();
    _star->setVisible(false);
    addChild(_star, kBackground, kSpriteStar);
}

void GameLayer::update(float delta) {
    if ( !_running ) {
        return;
    }

    _lineContainer->update(delta);
}
