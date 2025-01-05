#ifndef CHESSDECORATOR_H
#define CHESSDECORATOR_H

//#include "Chess.h"
#include "IChess.h"

// Refactored with Decorator Pattern
// װ�������࣬�̳���IChess
class ChessDecorator : public IChess {
protected:
    IChess* decoratedChess;  // ��װ�ε�IChess ����

public:
    ChessDecorator(IChess* chess) : decoratedChess(chess) {}
    virtual ~ChessDecorator() {}

    // ��д�ӿڷ��������ñ�װ�ζ���ķ���
    virtual void deleteChess() override {
        decoratedChess->deleteChess();
    }

    virtual int getId() const override {
        return decoratedChess->getId();
    }

    virtual int getStar() const override {
        return decoratedChess->getStar();
    }

    virtual bool isInGrid() const override {
        return decoratedChess->isInGrid();
    }

    virtual bool isAtSeat() const override {
        return decoratedChess->isAtSeat();
    }

    virtual IChess* createByIdAndStar(int id, int star) override {
        return decoratedChess->createByIdAndStar(id, star);
    }

    virtual void upgrade() override {
        return decoratedChess->upgrade();
    }

    virtual void upgradeToSecond(const std::string& filename) override {
        decoratedChess->upgradeToSecond(filename);
    }

    virtual void upgradeToThird(const std::string& filename) override {
        decoratedChess->upgradeToThird(filename);
    }

    virtual void reverseImg() override {
        decoratedChess->reverseImg();
    }

    virtual void moveAction(GridMap* gridMap) override {
        decoratedChess->moveAction(gridMap);
    }

    virtual void attackAction(GridMap* gridMap) override {
        decoratedChess->attackAction(gridMap);
    }

    virtual void deadAction(GridMap* gridMap) override {
        decoratedChess->deadAction(gridMap);
    }

    virtual void getHurt(int ATK) override {
        decoratedChess->getHurt(ATK);
    }

    virtual void updateInBattle(float dt, GridMap* gridMap) override {
        decoratedChess->updateInBattle(dt, gridMap);
    }

    virtual void changeState(ChessState* newState) override {
        decoratedChess->changeState(newState);
    }

    virtual void initHealthBar() override {
        decoratedChess->initHealthBar();
    }

    virtual void initBlueBar() override {
        decoratedChess->initBlueBar();
    }

    // ��ʼ����ʹ�ü��ܷ�����װ�������еĽӿڣ�
    virtual bool init(const std::string& filename) = 0;// ���ﲻʵ�֣���������װ����ʵ��
    virtual void useSkill() = 0; // ���ﲻʵ�֣���������װ����ʵ��
};

#endif // CHESSDECORATOR_H
