#ifndef BACKGROUND_COMPONENT_H
#define BACKGROUND_COMPONENT_H

#include "Component.h"
#include "cocos2d.h"

class BackgroundComponent : public Component {
private:
    cocos2d::Sprite* backgroundImg;

public:
    virtual void init() override;
    virtual void update() override;
    virtual void draw() override;

    virtual ~BackgroundComponent();
};

#endif // BACKGROUND_COMPONENT_H
