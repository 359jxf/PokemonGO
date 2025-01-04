#ifndef CHESSDECORATOR_H
#define CHESSDECORATOR_H

//#include "Chess.h"
#include "IChess.h"

// Refactored with Decorator Pattern
// 装饰器基类，继承自IChess
class ChessDecorator : public IChess {
protected:
    IChess* decoratedChess;  // 被装饰的IChess 对象

public:
    ChessDecorator(IChess* chess) : decoratedChess(chess) {}
    virtual ~ChessDecorator() {}

    // 重写接口方法，调用被装饰对象的方法
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

    // 初始化、使用技能方法（装饰器独有的接口）
    virtual bool init(const std::string& filename) = 0;// 这里不实现，留给具体装饰器实现
    virtual void useSkill() = 0; // 这里不实现，留给具体装饰器实现
};

#endif // CHESSDECORATOR_H
