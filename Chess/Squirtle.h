//杰尼龟 1阶
#ifndef SQUIRTLE_H
#include"cocos2d.h"
//#include"Chess.h"
#include"ChessDecorator.h"

USING_NS_CC;

// Refactored with Decorator Pattern
// class Squirtle :public Chess
class Squirtle :public ChessDecorator
{
public:
	static Squirtle* create(const std::string& filename);

	//重写init方法
	bool init(const std::string& filename) override;

	//重写useSkill方法
	void useSkill() override;
};

#endif
