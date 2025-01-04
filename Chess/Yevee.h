//伊布 1阶
#ifndef YEVEE_H

#include"cocos2d.h"
//#include"Chess.h"
#include"ChessDecorator.h"

USING_NS_CC;

// Refactored with Decorator Pattern
// class Yevee :public Chess
class Yevee :public ChessDecorator
{
public:
	static Yevee* create(const std::string& filename);

	//重写init方法
	bool init(const std::string& filename) override;

	//重写useSkill方法
	void useSkill() override;
};

#endif
