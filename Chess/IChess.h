#ifndef ICHESS_H
#define ICHESS_H

#include "cocos2d.h"
#include "HealthBar.h"
#include "BlueBar.h"
#include "AudioEngine.h"
#include "ChessState.h"
class GridMap;
class HexCell;
class Seat;
class ChessFactory;
class ChessState;
USING_NS_CC;

// Refactored with Decorator Pattern
// 新加的IChess接口
class IChess{
public:
    virtual ~IChess() = default;

    //初始化棋子
    virtual Chess* create() = 0;

    //初始化棋子,用文件名初始化
    virtual Chess* create(const std::string& filename) = 0;

    // 获取棋子的ID
    virtual int getId() const = 0;

    // 获取棋子的星级
    virtual int getStar() const = 0;

    // 判断棋子是否在棋格中
    virtual bool isInGrid() const = 0;

    // 判断棋子是否在备战席上
    virtual bool isAtSeat() const = 0;

    // 棋子的移动行为
    virtual void moveAction(GridMap* gridMap) = 0;

    // 棋子的攻击行为
    virtual void attackAction(GridMap* gridMap) = 0;

    // 棋子的死亡行为
    virtual void deadAction(GridMap* gridMap) = 0;

    // 棋子受到伤害
    virtual void getHurt(int ATK) = 0;

    // 初始化血条
    virtual void initHealthBar() = 0;

    // 初始化蓝条
    virtual void initBlueBar() = 0;

    // 初始化棋子
    virtual bool init(const std::string& filename) = 0;

    // 棋子升级
    virtual void upgrade() = 0;

    // 棋子升级到第二等级
    virtual void upgradeToSecond(const std::string& filename) = 0;

    // 棋子升级到第三等级
    virtual void upgradeToThird(const std::string& filename) = 0;

    // 反转棋子图片
    virtual void reverseImg() = 0;

    // 更新棋子状态
    virtual void updateInBattle(float dt, GridMap* gridMap) = 0;

    // 改变棋子状态
    virtual void changeState(ChessState* newState) = 0;

    // 判断是否有敌人在攻击范围内
    virtual bool isEnemyInAttackRange(GridMap* gridMap, std::vector<HexCell*>& enemyChessAround) = 0;

    // 删除棋子
    virtual void deleteChess() = 0;

    // 创建棋子
    virtual IChess* create() = 0;

    // 根据文件名创建棋子
    virtual IChess* create(const std::string& filename) = 0;

    // 根据ID和星级创建棋子
    virtual IChess* createByIdAndStar(int id, int star) = 0;
};


#endif // ICHESS_H
