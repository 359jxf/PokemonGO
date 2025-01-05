#ifndef PROTOTYPEREGISTRY_H
#define PROTOTYPEREGISTRY_H
// refractored with prototype pattern
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


USING_NS_CC;
class PrototypeRegistry {
private:
	// 使用 std::map 存储 id 和创建函数的映射
	std::map<std::string, ChessCreator> creatorMap;

	// 原型注册表
	std::map<std::string, Prototype*> prototypeMap;

public:
	// 类型别名
	using ChessCreator = std::function<Chess*()>;  // 创建棋子对象的函数类型

	PrototypeRegistry() {};

	~PrototypeRegistry() {};

	// 添加原型到注册表
	void addItem(const std::string& id, Prototype* p) {};

	// 获取原型，如果原型不存在，则懒加载创建
	static Prototype* getById(const std::string& id) {};

};


#endif