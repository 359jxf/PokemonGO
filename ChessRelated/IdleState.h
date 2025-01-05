// Refactored with State Pattern
#ifndef IDLE_STATE_H
#define IDLE_STATE_H

#include "ChessState.h"

class IdleState : public ChessState {
public:
    // ���캯������ʽ���û��๹�캯��
    IdleState(Chess* chess) : ChessState(chess) {}

    void enterState() override;
    void update(GridMap* gridMap) override;
    void exitState() override;
    void action(GridMap* gridMap) override;
};

#endif // IDLE_STATE_H