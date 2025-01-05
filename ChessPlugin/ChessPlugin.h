//Refactored with Plugin Pattern
// ChessPlugin/ChessPlugin.h
#include "cocos2d.h"  
USING_NS_CC;

class ChessPlugin {
public:
    virtual ~ChessPlugin() = default;

    // 获取棋子名称
    virtual std::string getName() const = 0;

    // 获取棋子 ID
    virtual int getId() const = 0;

    // 创建棋子
    virtual Chess* createChess() const = 0;

    // 获取棋子属性
    virtual int getHp() const = 0;
    virtual int getAttack() const = 0;
    virtual float getAttackSpeed() const = 0;
    virtual float getMoveSpeed() const = 0;
    virtual int getAttackRange() const = 0;
    virtual bool isMelee() const = 0;
    virtual int getPrice() const = 0;
    virtual int getOriginalCost() const = 0;
};