#pragma once
#include"cocos2d.h"
//#include"Chess.h"
#include"ChessDecorator.h"

USING_NS_CC;

// Refactored with Decorator Pattern
// class Magikarp :public Chess
class Magikarp :public ChessDecorator
{
public:
	static Magikarp* create(const std::string& filename);

	//��дinit����
	bool init(const std::string& filename) override;

	//��дuseSkill����
	void useSkill() override;
};
