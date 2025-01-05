#ifndef CHESS_H
#define CHESS_H

#include "cocos2d.h"
#include "HealthBar.h"
#include "BlueBar.h"
#include"AudioEngine.h"

#include "Prototype.h"
class GridMap;
class HexCell;
class Seat;
// class ChessFactory;
class PrototypeRegistry;
class ChessState;

USING_NS_CC;

#define SET_SCALE 0.15//������ģ�ʹ�С����������
#define MAX_ID 8//��࿨����
#define PRICE_STAR1_GRADE1 1//1��1�׿��ķ���
#define PRICE_STAR1_GRADE2 2//1��2�׿��ķ���
#define PRICE_STAR1_GRADE3 5//1��3�׿��ķ���

#define PRICE_STAR2_GRADE1 2//2��1�׿��ķ���
#define PRICE_STAR2_GRADE2 5//2��2�׿��ķ���
#define PRICE_STAR2_GRADE3 14//2��3�׿��ķ���

#define PRICE_STAR3_GRADE1 3//3��1�׿��ķ���
#define PRICE_STAR3_GRADE2 8//3��2�׿��ķ���
#define PRICE_STAR3_GRADE3 23//3��3�׿��ķ���
#define CHESS_ATK 10
#define CHESS_HEALTH 100

// Refactored with Decorator and Prototype Pattern 
//class Chess :public cocos2d::Sprite
class Chess : public cocos2d::Sprite, public IChess, public Prototype

{

public://�˴������Ա���

	Vec2 atGridPosition = Vec2(-1, -1);//�����������������������,��һ����coordinateChess���Ӧ��λ������,�ǵ���Ϊ-1��

	int atSeatPosition = -1;//�����������ı�սϯ������꣬��Seat.number���Ӧ���ǵ���Ϊ-1��

	bool isDragging = false;//���϶����ж�

	std::string name;//����

	int id;//����id

	int star;//�����Ǽ�

	int ATK = CHESS_ATK;//������

	int growATK;//�ɳ���������

	int growHP;//�ɳ���������

	float attackSpeed ;//�����ٶȣ���ΧΪ0-9

	float moveSpeed = 1.0;//�ƶ��ٶ�

	int health = CHESS_HEALTH;//����ֵ����ʼ��100

	int maxHP;//��������

	int blueBar;//��д��Bar���������ޣ�Сд��bar�ǵ�ǰ����ֵ

	int currentBlueBar = 0;//��ǰ����

	bool enable_skill = false;//�ܷ�ż���

	int skillCount = 0;//ʹ�ü��ܴ���

	int attackRange;//������Χ

	int price;//���ۼ۸�

	int originalCost;//����ʱ�ķ���

	bool isMelee;//1��ʱ���ʾ��ս��0��ʱ���ʾԶ��

	int playerNumber;//������������ұ��

	enum State { Idle, Moving, Attacking, Dead };

	State currentState = Idle;//���浱ǰ����״̬

	bool isAnimationPlaying = false;//�Ƿ����ڲ��Ŷ���

	HealthBar* healthBar;//Ѫ��
	BlueBar* bluebar;//����
public:
	// Refactored with Decorator Pattern
	// IChess中函数的实现
	Chess();
	~Chess();
	int getId() const override;
	int getStar() const override;
	bool isInGrid() const override;
	bool isAtSeat() const override;
	void moveAction(GridMap* gridMap) override;
	void attackAction(GridMap* gridMap) override;
	void deadAction(GridMap* gridMap) override;
	void getHurt(int ATK) override;
	void initHealthBar() override;
	void initBlueBar() override;
	void upgrade() override;
	void upgradeToSecond(const std::string& filename) override;
	void upgradeToThird(const std::string& filename) override;
	void reverseImg() override;
	void updateInBattle(float dt, GridMap* gridMap) override;
	void changeState(ChessState* newState) override; // Refactored with State Pattern
	bool isEnemyInAttackRange(GridMap* gridMap, std::vector<HexCell*>& enemyChessAround) override;
	void deleteChess() override;
	Chess* create() override;
	Chess* create(const std::string& filename) override;
	Chess* createByIdAndStar(int id, int star) override;
  
  // refractored with prototype pattern
	Prototype* clone() const override {};

};


#endif // Chess.h
