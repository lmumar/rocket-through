//
//  GameSprite.cpp
//  rocket-through
//
//  Created by Lord Norlan Mumar on 5/19/14.
//
//

#include "GameSprite.h"

GameSprite* GameSprite::createWithFrameName(const std::string& frameName) {
    GameSprite *sprite = new GameSprite();

    if (sprite && sprite->initWithSpriteFrameName(frameName)) {
        sprite->autorelease();
    } else {
        CC_SAFE_DELETE(sprite);
    }

    return sprite;
}
