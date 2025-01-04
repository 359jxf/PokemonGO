// Refactored with State Pattern
#include "MovingState.h"
#include "Chess.h
#include "GridMap.h"
#include "IdleState.h"

void MovingState::enterState() {
    //CCLOG("Chess entered Moving State");
}

void MovingState::update(GridMap* gridMap) {
    if (!chess->isAnimationPlaying) { // 如果动画未播放
        this->action(gridMap); // 执行移动逻辑
    }
    return;
}

void MovingState::exitState() {
    //CCLOG("Chess entered Moving State");
}

void MovingState::action(GridMap* gridMap) {
    HexCell* fromCell = gridMap->getCellAtPosition(atGridPosition);
    HexCell* toCell = gridMap->FindBattle(chess, fromCell);
    //获得路径
    Vector<HexCell*> movePath;
    gridMap->FindPath(movePath, chess, fromCell, toCell, chess->attackRange);
    if (movePath.size() <= 0)
        return;
    //让开始的移动位置停止被预定，移动路上的棋子开始被预定
    fromCell->isBooked = false;
    movePath.at(0)->isBooked = true;

    //以棋子当前位置为起点，目标位置为终点，持续时间为距离除以移动速度
    auto targetPosition = movePath.at(0)->getPosition();
    auto distance = targetPosition.distance(chess->getPosition());
    auto move_Action = MoveTo::create(distance / (chess->moveSpeed * 100), targetPosition);

    auto callback = CallFunc::create([=]() {
        // 动画完成后的回调,将棋子放置到新的位置
        gridMap->addChessToGrid(chess, movePath.at(0));
        gridMap->removeChessOfGrid(fromCell);
        //注意回调函数中需要重新设置book的位置
        fromCell->isBooked = false;
        movePath.at(0)->isBooked = true;
        chess->isAnimationPlaying = false;
        chess->changeState(new IdleState(chess)); // 或其他状态
        });

    auto sequence = Sequence::create(move_Action, callback, nullptr);
    chess->runAction(sequence);
    chess->isAnimationPlaying = true;
}