//
//  Rocket.h
//  rocket-through
//
//  Created by Lord Norlan Mumar on 5/19/14.
//
//

#ifndef __Rocket_H__
#define __Rocket_H__

#include <memory>
#include "cocos2d.h"
#include "GameSprite.h"

USING_NS_CC;

class Rocket : public GameSprite {
public:
    static Rocket* create();
};

#endif