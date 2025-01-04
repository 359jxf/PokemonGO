#pragma once
#include"cocos2d.h"
//#include"Chess.h"
#include"ChessDecorator.h"

USING_NS_CC;

// Refactored with Decorator Pattern
// class Bulbasaur :public Chess
class Bulbasaur :public ChessDecorator
{
public:
	//create一个妙蛙种子
	static Bulbasaur* create(const std::string& filename);

	//重写init方法
	bool init(const std::string& filename) override;

	//重写useSkill方法
	void useSkill() override;
};