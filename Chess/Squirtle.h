//����� 1��
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

	//��дinit����
	bool init(const std::string& filename) override;

	//��дuseSkill����
	void useSkill() override;
};

#endif
