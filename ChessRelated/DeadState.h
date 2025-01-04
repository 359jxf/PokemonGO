// Refactored with State Pattern
#ifndef DEAD_STATE_H
#define DEAD_STATE_H

#include "ChessState.h"

class DeadState : public ChessState {
public:
    // 构造函数，显式调用基类构造函数
    DeadState(Chess* chess) : ChessState(chess) {}

    void enterState() override;
    void update(GridMap* gridMap) override;
    void exitState() override;
    void action(GridMap* gridMap) override;
};

#endif