#include "EventType.h"
class IObserver {
public:
    virtual void update(EventType event,Vec2 position) = 0;  // ��״̬�仯ʱ���ø÷���
    virtual ~IObserver() = default;
};
