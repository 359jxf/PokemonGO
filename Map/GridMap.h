#ifndef GRIDMAP_H
#define GRIDMAP_H

#include "cocos2d.h"
#include "HexCell.h"
#include "./Chess/Chess.h"
#include <algorithm>
#include "map"
#include "CompositeComponent.h"
#include "IObserver.h"
#define NUM_COLUMN 14//��������
#define NUM_LINE 8//����

class Vec2Compare {
public:
    //�Ƚ���������ǰ��˳��
    bool operator()(const Vec2& v1, const Vec2& v2) const {
        return (v1.x < v2.x) || (v1.x == v2.x && v1.y < v2.y);
    }
};
// refactoring with composite pattern
class GridMap : public cocos2d::Node, public CompositeComponent, public IObserver {
private:
    HexCell* lastCell = nullptr;//��һ��ѡ�е����
public:
    int chessAmount=0;//��¼��������

    EventListenerMouse* mouseListener;

    std::map<Vec2, HexCell*, Vec2Compare>nodeMap;

    std::map<Vec2, Chess*, Vec2Compare>myChessMap;
public:

    //����������Ϣ������ʾ
    void updateForPlayer();
    // ������ֹͣ schedule
    void selectSchedule(bool select);

    //��������
    static GridMap* create(std::map<Vec2, Chess*, Vec2Compare>myChessMap);

    //��ʼ�������������
    virtual bool init();

    //�Ƿ������̷�Χ
    bool isInBoard(Vec2 coor)const;

    //�����Ϸ������Vec2����Ӧ�ĸ��ӣ�����Ϊ�����������������ĸ������ģ�
    HexCell* mouseInWhichCell(const cocos2d::Vec2& position);

    //ѡ����������ʾ
    void selectGrid(Event* event);

    // ���ú��������������ķ���
    void disableMouseListener();
    void enableMouseListener();

    //Ѱ·�㷨
    bool FindPath(Vector<HexCell*>& Path, Chess* InActor, HexCell* FromNode, HexCell* ToNode, int StopSteps = 0);

    //
    HexCell* FindBattle(Chess* InActor, HexCell* FromNode);

    //��ȡһ��������Χ�ڵ������������
    Vector<HexCell*> GetNodeNeighbors(HexCell* inNode, int stepRange);

    //���һ�����ӵ������
    void addChessToGrid(Chess* chess, HexCell* cell);

    //��һ������ϵ�����ȥ��
    void removeChessOfGrid(HexCell* Incell);

    //����һ��Vec2ֵ�����ض�Ӧ��HexCell*
    HexCell* getCellAtPosition(Vec2 position);
    
    // refactored with observer pattern
    virtual void update(EventType* event, Vec2 position);

};

#endif // HEXGRID_H
