#include <map>
#include <memory>
#include <iostream>
#include <stdexcept>
#include "PrototypeRegistry.h"
// refractored with prototype pattern

PrototypeRegistry::PrototypeRegistry() {
	// 初始化映射表
	creatorMap["11"] = []() { return Magikarp::create("Magikarp-right-1.png"); };
	creatorMap["12"] = []() { return Buneary::create("Buneary-right-1.png"); };
	creatorMap["13"] = []() { return Jingglypuff::create("Jigglypuff-right-1.png"); };
	creatorMap["21"] = []() { return Yevee::create("Yevee-right-1.png"); };
	creatorMap["22"] = []() { return Squirtle::create("Squirtle-right-1.png"); };
	creatorMap["23"] = []() { return Charmander::create("Charmander-right-1.png"); };
	creatorMap["24"] = []() { return Bulbasaur::create("Bulbasaur-right-1.png"); };
	creatorMap["25"] = []() { return Pikachu::create("Pikachu-right-1.png"); };
	creatorMap["31"] = []() { return Snorlax::create("Snorlax-right-1.png"); };
	creatorMap["32"] = []() { return Mewtwo::create("Mewtwo-right-1.png"); };
	creatorMap["33"] = []() { return Rugia::create("Rugia-right-1.png"); };
}

PrototypeRegistry::~PrototypeRegistry() {
	// 删除所有注册的原型对象
	for (auto& entry : prototypeMap) {
		delete entry.second;
	}
}

// 添加原型到注册表
void PrototypeRegistry::addItem(const std::string& id, Prototype* p) {
	if (prototypeMap.find(id) != prototypeMap.end()) {
		throw std::runtime_error("Prototype with id " + id + " already exists.");
	}
	prototypeMap[id] = p;
}

// 获取原型，如果原型不存在，则懒加载创建
Prototype* PrototypeRegistry::getById(const std::string& id) {
	// 如果原型未注册
	if (prototypeMap.find(id) == prototypeMap.end()) {
		Chess* chess = nullptr;  // 声明 chess 变量

		if (creatorMap.find(id) != creatorMap.end()) {
			chess = creatorMap[id]();  // 调用相应的创建函数
			addItem(id, chess);
			return chess;
		}
		else {
			throw std::runtime_error("Unknown prototype id: " + id);
		}
	}

	// 注册过返回原型的副本
	return prototypeMap[id]->clone();  
}

