// Refactored with State Pattern
#include "DeadState.h"
#include "Chess.h"

void DeadState::enterState() {
    //CCLOG("Chess entered Dead State");
}

void DeadState::update(GridMap* gridMap) {
    this->action(gridMap); // ִ�������߼�
}

void DeadState::exitState() {
    //CCLOG("Chess exited Dead State");
}

void DeadState::action(GridMap* gridMap) {
    if (chess->isAnimationPlaying) {
        chess->stopAllActions();
    }

    // ���������߼�
    auto fadeOut = FadeOut::create(0.3f);

    // ����Sequence�������������������ͻص��������Ƴ��ڵ���߼���
    auto sequence = Sequence::create(
        fadeOut,
        CallFunc::create([chess, gridMap]() {
            chess->removeFromParentAndCleanup(true); // �Ƴ���ִ���������
            }),
        nullptr
    );

    // �Խ�ɫ��Ѫ���������ֱ�Ӧ�ö�����Sequence����
    chess->runAction(sequence);
    //chess->healthBar->runAction(fadeOut);
    //chess->bluebar->runAction(fadeOut);
    gridMap->removeChessOfGrid(gridMap->getCellAtPosition(chess->atGridPosition));
    //chess->removeFromParentAndCleanup(true);
}