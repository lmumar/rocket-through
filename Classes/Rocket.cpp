//
//  Rocket.cpp
//  rocket-through
//
//  Created by Lord Norlan Mumar on 5/19/14.
//
//

#include "Rocket.h"

Rocket* Rocket::create() {
    Rocket *sprite = new Rocket;

    if (sprite && sprite->initWithSpriteFrameName("rocket.png")) {
        sprite->autorelease();
    } else {
        CC_SAFE_DELETE(sprite);
    }
    
    return sprite;
}
