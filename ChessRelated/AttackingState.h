// Refactored with State Pattern
#ifndef ATTACKING_STATE_H
#define ATTACKING_STATE_H

#include "ChessState.h"

class AttackingState : public ChessState {
public:
    // ���캯������ʽ���û��๹�캯��
    AttackingState(Chess* chess) : ChessState(chess) {}

    void enterState() override;
    void update(GridMap* gridMap) override;
    void exitState() override;
    void action(GridMap* gridMap) override;
};

#endif // ATTACKING_STATE_H