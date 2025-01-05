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
    // ���������Ķ���
    ChessState(Chess* context) {
        this->chess = context;
    }

    virtual ~ChessState() = default;

    // ��������״̬���еĽӿ�
    virtual void enterState() = 0; // ״̬����ʱ���߼�
    virtual void update(GridMap* gridMap) = 0; // ÿ֡�����߼�
    virtual void exitState() = 0; // ״̬�˳�ʱ���߼�
    virtual void action(GridMap* gridMap) = 0; //ִ�о��嶯��
};
#endif // CHESS_STATE_H