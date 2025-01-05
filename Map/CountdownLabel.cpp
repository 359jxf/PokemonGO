// refactored with Observer pattern
#include "CountdownLabel.h"

CountdownLabel::CountdownLabel()
{
    remainingTime = PREPARE_TIME;
    countdownLabel = Label::createWithTTF("10", "fonts/arial.ttf", 50);
    countdownLine = DrawNode::create();
    countdownLine->setAnchorPoint(Vec2(0, 0.5));
    countdownLine->setPosition(Vec2(0, 100));
}

void CountdownLabel::init()
{
    this->addChild(countdownLine);
    this->addChild(countdownLabel);
}

void CountdownLabel::update()
{
    remainingTime -= 0.01f;
    int seconds = static_cast<int>(remainingTime) + 1;

    float lengthRatio = remainingTime / PREPARE_TIME;
    float lineWidth = 30.0f;

    countdownLine->clear();
    countdownLine->drawLine(Vec2(300, 600), Vec2(300 + 700 * lengthRatio, 600), Color4F::WHITE);
    countdownLine->setLineWidth(lineWidth);
    countdownLabel->setString(StringUtils::format("%d", seconds));
}

