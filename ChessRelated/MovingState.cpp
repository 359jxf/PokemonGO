// Refactored with State Pattern
#include "MovingState.h"
#include "Chess.h
#include "GridMap.h"
#include "IdleState.h"

void MovingState::enterState() {
    //CCLOG("Chess entered Moving State");
}

void MovingState::update(GridMap* gridMap) {
    if (!chess->isAnimationPlaying) { // �������δ����
        this->action(gridMap); // ִ���ƶ��߼�
    }
    return;
}

void MovingState::exitState() {
    //CCLOG("Chess entered Moving State");
}

void MovingState::action(GridMap* gridMap) {
    HexCell* fromCell = gridMap->getCellAtPosition(atGridPosition);
    HexCell* toCell = gridMap->FindBattle(chess, fromCell);
    //���·��
    Vector<HexCell*> movePath;
    gridMap->FindPath(movePath, chess, fromCell, toCell, chess->attackRange);
    if (movePath.size() <= 0)
        return;
    //�ÿ�ʼ���ƶ�λ��ֹͣ��Ԥ�����ƶ�·�ϵ����ӿ�ʼ��Ԥ��
    fromCell->isBooked = false;
    movePath.at(0)->isBooked = true;

    //�����ӵ�ǰλ��Ϊ��㣬Ŀ��λ��Ϊ�յ㣬����ʱ��Ϊ��������ƶ��ٶ�
    auto targetPosition = movePath.at(0)->getPosition();
    auto distance = targetPosition.distance(chess->getPosition());
    auto move_Action = MoveTo::create(distance / (chess->moveSpeed * 100), targetPosition);

    auto callback = CallFunc::create([=]() {
        // ������ɺ�Ļص�,�����ӷ��õ��µ�λ��
        gridMap->addChessToGrid(chess, movePath.at(0));
        gridMap->removeChessOfGrid(fromCell);
        //ע��ص���������Ҫ��������book��λ��
        fromCell->isBooked = false;
        movePath.at(0)->isBooked = true;
        chess->isAnimationPlaying = false;
        chess->changeState(new IdleState(chess)); // ������״̬
        });

    auto sequence = Sequence::create(move_Action, callback, nullptr);
    chess->runAction(sequence);
    chess->isAnimationPlaying = true;
}