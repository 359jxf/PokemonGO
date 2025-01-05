#ifndef STORE_COMPONENT_H
#define STORE_COMPONENT_H

#include "Component.h"
#include "Store.h"  

class StoreComponent : public Component {
private:
    Store* store;

public:
    virtual void init() override;
    virtual void update() override;
    virtual void draw() override;

    virtual ~StoreComponent();
};

#endif