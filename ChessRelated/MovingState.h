// Refactored with State Pattern
#ifndef MOVING_STATE_H
#define MOVING_STATE_H

#include "ChessState.h"

class MovingState : public ChessState {
public:
    // 构造函数，显式调用基类构造函数
    MovingState(Chess* chess) : ChessState(chess) {}

    void enterState() override;
    void update(GridMap* gridMap) override;
    void exitState() override;
    void action(GridMap* gridMap) override;
};

#endif