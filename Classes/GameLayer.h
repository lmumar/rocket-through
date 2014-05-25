#ifndef __GAME_LAYER_H__
#define __GAME_LAYER_H__

#include "cocos2d.h"

enum {
    kBackground,
    kMiddleground,
    kForeground
};

enum {
    kSpriteRocket,
    kSpritePlanet,
    kSpriteBoost,
    kSpriteStar
};

enum class GameStates {
    INTRO,
    PAUSED,
    PLAY,
    OVER
};

class Rocket;
class LineContainer;

class GameLayer : public cocos2d::Layer {
private:
    cocos2d::Vector<cocos2d::Sprite *> _planets;

    LineContainer *_lineContainer;
    Rocket *_rocket;

    cocos2d::ParticleSystemQuad *_jet;
    cocos2d::ParticleSystemQuad *_boom;
    cocos2d::ParticleSystemQuad *_comet;
    cocos2d::ParticleSystemQuad *_pickup;
    cocos2d::ParticleSystemQuad *_warp;
    cocos2d::ParticleSystemQuad *_star;

    cocos2d::Size _screenSize;

    GameStates _state;
    bool       _running;
    
    std::vector<cocos2d::Point> _grid;

public:
    static cocos2d::Scene* createScene();
    
    ~GameLayer();
    
    virtual bool init();
    
    void createGameScreen();
    void createParticles();
    void update(float delta);

    CREATE_FUNC(GameLayer);
};

#endif
