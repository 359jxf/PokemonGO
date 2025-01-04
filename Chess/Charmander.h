//С���� 1��
#ifndef CHARMANDER_H
#include"cocos2d.h"
//#include"Chess.h"
#include"ChessDecorator.h"

USING_NS_CC;

// Refactored with Decorator Pattern
// class Charmander :public Chess
class Charmander :public ChessDecorator
{
public:
	static Charmander* create(const std::string& filename);

	//��дinit����
	bool init(const std::string& filename) override;

	//��дuseSkill����
	void useSkill() override;
};
#endif
