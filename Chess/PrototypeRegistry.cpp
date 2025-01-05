#include <map>
#include <memory>
#include <iostream>
#include <stdexcept>
#include "PrototypeRegistry.h"
// refractored with prototype pattern

PrototypeRegistry::PrototypeRegistry() {
	// ��ʼ��ӳ���
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
	// ɾ������ע���ԭ�Ͷ���
	for (auto& entry : prototypeMap) {
		delete entry.second;
	}
}

// ���ԭ�͵�ע���
void PrototypeRegistry::addItem(const std::string& id, Prototype* p) {
	if (prototypeMap.find(id) != prototypeMap.end()) {
		throw std::runtime_error("Prototype with id " + id + " already exists.");
	}
	prototypeMap[id] = p;
}

// ��ȡԭ�ͣ����ԭ�Ͳ����ڣ��������ش���
Prototype* PrototypeRegistry::getById(const std::string& id) {
	// ���ԭ��δע��
	if (prototypeMap.find(id) == prototypeMap.end()) {
		Chess* chess = nullptr;  // ���� chess ����

		if (creatorMap.find(id) != creatorMap.end()) {
			chess = creatorMap[id]();  // ������Ӧ�Ĵ�������
			addItem(id, chess);
			return chess;
		}
		else {
			throw std::runtime_error("Unknown prototype id: " + id);
		}
	}

	// ע�������ԭ�͵ĸ���
	return prototypeMap[id]->clone();  
}

