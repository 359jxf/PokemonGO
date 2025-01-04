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
// �¼ӵ�IChess�ӿ�
class IChess{
public:
    virtual ~IChess() = default;

    //��ʼ������
    virtual Chess* create() = 0;

    //��ʼ������,���ļ�����ʼ��
    virtual Chess* create(const std::string& filename) = 0;

    // ��ȡ���ӵ�ID
    virtual int getId() const = 0;

    // ��ȡ���ӵ��Ǽ�
    virtual int getStar() const = 0;

    // �ж������Ƿ��������
    virtual bool isInGrid() const = 0;

    // �ж������Ƿ��ڱ�սϯ��
    virtual bool isAtSeat() const = 0;

    // ���ӵ��ƶ���Ϊ
    virtual void moveAction(GridMap* gridMap) = 0;

    // ���ӵĹ�����Ϊ
    virtual void attackAction(GridMap* gridMap) = 0;

    // ���ӵ�������Ϊ
    virtual void deadAction(GridMap* gridMap) = 0;

    // �����ܵ��˺�
    virtual void getHurt(int ATK) = 0;

    // ��ʼ��Ѫ��
    virtual void initHealthBar() = 0;

    // ��ʼ������
    virtual void initBlueBar() = 0;

    // ��ʼ������
    virtual bool init(const std::string& filename) = 0;

    // ��������
    virtual void upgrade() = 0;

    // �����������ڶ��ȼ�
    virtual void upgradeToSecond(const std::string& filename) = 0;

    // ���������������ȼ�
    virtual void upgradeToThird(const std::string& filename) = 0;

    // ��ת����ͼƬ
    virtual void reverseImg() = 0;

    // ��������״̬
    virtual void updateInBattle(float dt, GridMap* gridMap) = 0;

    // �ı�����״̬
    virtual void changeState(ChessState* newState) = 0;

    // �ж��Ƿ��е����ڹ�����Χ��
    virtual bool isEnemyInAttackRange(GridMap* gridMap, std::vector<HexCell*>& enemyChessAround) = 0;

    // ɾ������
    virtual void deleteChess() = 0;

    // ��������
    virtual IChess* create() = 0;

    // �����ļ�����������
    virtual IChess* create(const std::string& filename) = 0;

    // ����ID���Ǽ���������
    virtual IChess* createByIdAndStar(int id, int star) = 0;
};


#endif // ICHESS_H
