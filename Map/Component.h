#ifndef COMPONENT_H
#define COMPONENT_H

class Component {
public:
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
    virtual ~Component() {}
};

#endif // COMPONENT_H
