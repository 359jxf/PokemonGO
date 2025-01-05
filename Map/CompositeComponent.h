class CompositeComponent : public Component {
private:
    Vector<Component*> children;

public:
    void addChild(Component* child) {
        children.pushBack(child);
    }

    void removeChild(Component* child) {
        children.eraseObject(child);
    }

    // 实现 Component 接口
    virtual void init() override {
        for (auto& child : children) {
            child->init();
        }
    }

    virtual void update() override {
        for (auto& child : children) {
            child->update();
        }
    }

    virtual void draw() override {
        for (auto& child : children) {
            child->draw();
        }
    }

    ~CompositeComponent() {
        for (auto& child : children) {
            delete child;
        }
    }
};
