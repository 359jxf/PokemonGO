// refactored with observer pattern
#include "EventType.h"
class ISubject {
public:
    virtual void addObserver(IObserver* observer) = 0; 
    virtual void removeObserver(IObserver* observer) = 0;
    virtual void notifyObservers(EventType event, Vec2 position) = 0;  
    virtual ~ISubject() = default;
};
