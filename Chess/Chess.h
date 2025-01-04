#ifndef CHESS_H
#define CHESS_H

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

#define SET_SCALE 0.15//对棋子模型大小的缩放设置
#define MAX_ID 8//最多卡牌数
#define PRICE_STAR1_GRADE1 1//1星1阶卡的费用
#define PRICE_STAR1_GRADE2 2//1星2阶卡的费用
#define PRICE_STAR1_GRADE3 5//1星3阶卡的费用

#define PRICE_STAR2_GRADE1 2//2星1阶卡的费用
#define PRICE_STAR2_GRADE2 5//2星2阶卡的费用
#define PRICE_STAR2_GRADE3 14//2星3阶卡的费用

#define PRICE_STAR3_GRADE1 3//3星1阶卡的费用
#define PRICE_STAR3_GRADE2 8//3星2阶卡的费用
#define PRICE_STAR3_GRADE3 23//3星3阶卡的费用
#define CHESS_ATK 10
#define CHESS_HEALTH 100


// Refactored with Decorator Pattern
//class Chess :public cocos2d::Sprite
class Chess : public cocos2d::Sprite, public IChess
{
private:
	ChessState* currentState; // Refactored with State Pattern

public://此处放属性变量

	Vec2 atGridPosition = Vec2(-1, -1);//该棋子所处的棋盘相对坐标,是一个与coordinateChess相对应的位置坐标,记得置为-1！

	int atSeatPosition = -1;//该棋子所处的备战席相对坐标，与Seat.number相对应，记得置为-1！

	bool isDragging = false;//被拖动的判断

	std::string name;//名字

	int id;//卡牌id

	int star;//卡牌星级

	int ATK = CHESS_ATK;//攻击力

	int growATK;//成长攻击属性

	int growHP;//成长生命属性

	float attackSpeed ;//攻击速度，范围为0-9

	float moveSpeed = 1.0;//移动速度

	int health = CHESS_HEALTH;//生命值，初始化100

	int maxHP;//生命上限

	int blueBar;//大写的Bar是蓝条上限，小写的bar是当前蓝条值

	int currentBlueBar = 0;//当前蓝条

	bool enable_skill = false;//能否放技能

	int skillCount = 0;//使用技能次数

	int attackRange;//攻击范围

	int price;//出售价格

	int originalCost;//购买时的费用

	bool isMelee;//1的时候表示近战，0的时候表示远程

	int playerNumber;//棋子所属的玩家编号

	//enum State { Idle, Moving, Attacking, Dead };

	//State currentState = Idle;//保存当前棋子状态

	bool isAnimationPlaying = false;//是否正在播放动画

	HealthBar* healthBar;//血条
	BlueBar* bluebar;//蓝条
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
	void changeState(ChessState* newState) override;
	bool isEnemyInAttackRange(GridMap* gridMap, std::vector<HexCell*>& enemyChessAround) override;
	void deleteChess() override;
	Chess* create() override;
	Chess* create(const std::string& filename) override;
	Chess* createByIdAndStar(int id, int star) override;
};

#endif // Chess.h
