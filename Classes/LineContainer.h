//
//  LineContainer.h
//  rocket-through
//
//  Created by Lord Norlan Mumar on 5/25/14.
//
//

#ifndef __LINE_CONTAINER_H__
#define __LINE_CONTAINER_H__

#include "cocos2d.h"

enum class LineType {
    TEMP,
    DASHED,
    NONE
};

class LineContainer : public cocos2d::Node {
public:
    CC_SYNTHESIZE(float, _energy, Energy);
    CC_SYNTHESIZE(cocos2d::Point, _pivot, Pivot);
    CC_SYNTHESIZE(cocos2d::Point, _tip, Tip);
    CC_SYNTHESIZE(float, _lineLength, LineLength);
    CC_SYNTHESIZE(LineType, _lineType, LineType);
    
    LineContainer();
    static LineContainer* create();

    virtual void draw(cocos2d::Renderer *renderer, const kmMat4& transform, bool transformUpdated) override;

    void update(float delta);
    void setEnergyDecrement(float value);
    void reset();

private:
    cocos2d::Size  _screenSize;

    float _lineAngle;
    float _energyLineX;
    float _energyHeight;
    float _energyDecrement;
    int   _dash;
    int   _dashSpace;
};

#endif
