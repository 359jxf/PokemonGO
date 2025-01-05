#include "BackgroundComponent.h"

void BackgroundComponent::init() {
    backgroundImg = cocos2d::Sprite::create("battle-background2.png");
    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();
    backgroundImg->setPosition(cocos2d::Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    backgroundImg->setScaleX(visibleSize.width / backgroundImg->getContentSize().width);
    backgroundImg->setScaleY(visibleSize.height / backgroundImg->getContentSize().height);
}

void BackgroundComponent::update() {
    // nothing
}

void BackgroundComponent::draw() {
    // draw
    cocos2d::Director::getInstance()->getRenderer()->render(backgroundImg);
}

BackgroundComponent::~BackgroundComponent() {
    if (backgroundImg) {
        backgroundImg->release();
    }
}
