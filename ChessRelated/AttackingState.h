// Refactored with State Pattern
#ifndef ATTACKING_STATE_H
#define ATTACKING_STATE_H

#include "ChessState.h"

class AttackingState : public ChessState {
public:
    // 构造函数，显式调用基类构造函数
    AttackingState(Chess* chess) : ChessState(chess) {}

    void enterState() override;
    void update(GridMap* gridMap) override;
    void exitState() override;
    void action(GridMap* gridMap) override;
};

#endif // ATTACKING_STATE_H