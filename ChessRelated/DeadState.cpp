// Refactored with State Pattern
#include "DeadState.h"
#include "Chess.h"

void DeadState::enterState() {
    //CCLOG("Chess entered Dead State");
}

void DeadState::update(GridMap* gridMap) {
    this->action(gridMap); // 执行死亡逻辑
}

void DeadState::exitState() {
    //CCLOG("Chess exited Dead State");
}

void DeadState::action(GridMap* gridMap) {
    if (chess->isAnimationPlaying) {
        chess->stopAllActions();
    }

    // 处理死亡逻辑
    auto fadeOut = FadeOut::create(0.3f);

    // 创建Sequence动作，包含淡出动作和回调函数（移除节点的逻辑）
    auto sequence = Sequence::create(
        fadeOut,
        CallFunc::create([chess, gridMap]() {
            chess->removeFromParentAndCleanup(true); // 移除并执行清理操作
            }),
        nullptr
    );

    // 对角色、血条和蓝条分别应用独立的Sequence动作
    chess->runAction(sequence);
    //chess->healthBar->runAction(fadeOut);
    //chess->bluebar->runAction(fadeOut);
    gridMap->removeChessOfGrid(gridMap->getCellAtPosition(chess->atGridPosition));
    //chess->removeFromParentAndCleanup(true);
}