#include "GameLayer.h"
#include "Rocket.h"

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
    _rocket = Rocket::create();
}

void GameLayer::createParticles() {
    _jet = ParticleSystemQuad::create("jet.plist");
    _jet->setSourcePosition(Point{-_rocket->getRadius() * 0.8f, 0});
    _jet->setAngle(180);
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
}

