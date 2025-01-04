// Refactored with State Pattern
#ifndef DEAD_STATE_H
#define DEAD_STATE_H

#include "ChessState.h"

class DeadState : public ChessState {
public:
    // ���캯������ʽ���û��๹�캯��
    DeadState(Chess* chess) : ChessState(chess) {}

    void enterState() override;
    void update(GridMap* gridMap) override;
    void exitState() override;
    void action(GridMap* gridMap) override;
};

#endif