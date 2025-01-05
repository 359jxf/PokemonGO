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
	// ʹ�� std::map �洢 id �ʹ���������ӳ��
	std::map<std::string, ChessCreator> creatorMap;

	// ԭ��ע���
	std::map<std::string, Prototype*> prototypeMap;

public:
	// ���ͱ���
	using ChessCreator = std::function<Chess*()>;  // �������Ӷ���ĺ�������

	PrototypeRegistry() {};

	~PrototypeRegistry() {};

	// ���ԭ�͵�ע���
	void addItem(const std::string& id, Prototype* p) {};

	// ��ȡԭ�ͣ����ԭ�Ͳ����ڣ��������ش���
	static Prototype* getById(const std::string& id) {};

};


#endif