//
//  LineContainer.cpp
//  rocket-through
//
//  Created by Lord Norlan Mumar on 5/25/14.
//
//

#include "LineContainer.h"

using namespace cocos2d;

LineContainer::LineContainer() :
    _dash(10), _dashSpace(10), _lineType(LineType::NONE) {
    _screenSize   = Director::getInstance()->getWinSize();
    _energyLineX  = _screenSize.width * 0.96f;
    _energyHeight = _screenSize.height * 0.8f;

    glLineWidth(8.0 * CC_CONTENT_SCALE_FACTOR());

    reset();
}

LineContainer* LineContainer::create() {
    LineContainer *node = new LineContainer;
    if (node) {
        node->autorelease();
        return node;
    }
    CC_SAFE_DELETE(node);
    return nullptr;
}

void LineContainer::reset() {
    _energy = 1.0f;
    _energyDecrement = 0.015f;
}

void LineContainer::draw(cocos2d::Renderer *renderer, const kmMat4& transform, bool transformUpdated) {
    switch (getLineType()) {
        case LineType::NONE:
            break;

        case LineType::TEMP:
            DrawPrimitives::setDrawColor4F(1.0, 1.0, 1.0, 1.0);
            DrawPrimitives::drawLine(getTip(), getPivot());
            DrawPrimitives::drawCircle(getPivot(), 10, CC_DEGREES_TO_RADIANS(360), 10, false);
            break;

        case LineType::DASHED:
            DrawPrimitives::setDrawColor4F(1.0, 1.0, 1.0, 1.0);
            DrawPrimitives::drawCircle(getPivot(), 10, M_PI, 10, false);

            int segments = getLineLength() / (_dash + _dashSpace);
            float t = 0.0f, x, y;
            for (int i = 0; i < segments; i++) {
                x = _pivot.x + t * (_tip.x - _pivot.x);
                y = _pivot.y + t * (_tip.y - _pivot.y);
                
                DrawPrimitives::drawCircle(Point{x, y}, 4, M_PI, 6, false);
                t += 1.0f/segments;
            }
            break;
    }

    // draw energy bar
    DrawPrimitives::setDrawColor4F(0.0, 0.0, 0.0, 1.0);
    DrawPrimitives::drawLine(Point{_energyLineX, _screenSize.height * 0.1f},
                             Point{_energyLineX, _screenSize.height * 0.9f});
    DrawPrimitives::setDrawColor4F(1.0, 0.5, 0.0, 1.0);
    DrawPrimitives::drawLine(Point{_energyLineX, _screenSize.height * 0.1f},
                             Point{_energyLineX, _screenSize.height * 0.1f + _energy + _energyHeight});
}

void LineContainer::update(float delta) {
    _energy -= delta * _energyDecrement;
}

void LineContainer::setEnergyDecrement(float value) {
    _energyDecrement += value;
}
