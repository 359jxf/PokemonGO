#include "EventType.h"
class IObserver {
public:
    virtual void update(EventType event,Vec2 position) = 0;  // 当状态变化时调用该方法
    virtual ~IObserver() = default;
};
