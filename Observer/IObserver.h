class IObserver {
public:
    virtual void update() = 0;  // 当状态变化时调用该方法
    virtual ~IObserver() = default;
};
