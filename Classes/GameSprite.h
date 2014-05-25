//
//  GameSprite.h
//  rocket-through
//
//  Created by Lord Norlan Mumar on 5/19/14.
//
//

#ifndef __GameSprite_H__
#define __GameSprite_H__

#include <memory>

#include "cocos2d.h"

USING_NS_CC;

class GameSprite : public Sprite {
public:
    CC_SYNTHESIZE(float, _radius, Radius);
    static GameSprite* createWithFrameName(const std::string& frameName);
};

#endif
