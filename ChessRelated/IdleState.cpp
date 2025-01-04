// Refatored with State Pattern
#include "IdleState.h"
#include "Chess.h"
#include "GridMap.h"
#include "AttackingState.h"
#include "MovingState.h"

void IdleState::enterState() {
    //CCLOG("Entering Idle State");
}

void IdleState::update(GridMap* gridMap) {
    this->action(gridMap);
}

void IdleState::exitState() {
    //CCLOG("Exiting Idle State");
}

void IdleState::action(GridMap* gridMap) {
    Vector<HexCell*> enemiesInRange;
    if (chess->isEnemyInAttackRange(gridMap, enemiesInRange)) {
        chess->changeState(new AttackingState(chess)); // ÇÐ»»µ½¹¥»÷×´Ì¬
    }
    else {
        chess->changeState(new MovingState(chess)); // ÇÐ»»µ½ÒÆ¶¯×´Ì¬
    }
}