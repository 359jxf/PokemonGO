#ifndef CHESSFACTORY_H
#define CHESSFACTORY_H



#include"Charmander.h"
#include"Yevee.h"
#include"Squirtle.h"
#include"Bulbasaur.h"
#include"Jingglypuff.h"
#include"Magikarp.h"
#include"Mewtwo.h"
#include"Pikachu.h"
#include"Buneary.h"
#include"Rugia.h"
#include"Snorlax.h"


#include "cocos2d.h"
#include "Chess.h"
#include "PluginManager.h"


USING_NS_CC;
class ChessFactory
{
public:
	ChessFactory(PluginManager& pluginManager);
	Chess* createChessById(int id);//创建不同id的1星棋子
private:
	PluginManager& pluginManager;//Refactored with Plugin Pattern
};

#endif