#pragma once
#include"cocos2d.h"
//#include"Chess.h"
#include"ChessDecorator.h"

USING_NS_CC;

// Refactored with Decorator Pattern
// class Mewtwo :public Chess
class Mewtwo :public ChessDecorator
{
public:
	static Mewtwo* create(const std::string& filename);

	//��дinit����
	bool init(const std::string& filename) override;

	//��дuseSkill����
	void useSkill() override;
};
