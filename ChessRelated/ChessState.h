// Refactored with State Pattern
#ifndef CHESS_STATE_H
#define CHESS_STATE_H

// #include "Chess.h"
// #include "GridMap.h"

class Chess;
class GridMap;

class ChessState {
protected:
    Chess* chess;
public:
    // 设置上下文对象
    ChessState(Chess* context) {
        this->chess = context;
    }

    virtual ~ChessState() = default;

    // 定义所有状态共有的接口
    virtual void enterState() = 0; // 状态进入时的逻辑
    virtual void update(GridMap* gridMap) = 0; // 每帧更新逻辑
    virtual void exitState() = 0; // 状态退出时的逻辑
    virtual void action(GridMap* gridMap) = 0; //执行具体动作
};
#endif // CHESS_STATE_H