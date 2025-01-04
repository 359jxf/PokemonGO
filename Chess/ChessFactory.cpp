#include "ChessFactory.h"
#include "PluginManager.h"

ChessFactory::ChessFactory(PluginManager& pluginManager) : pluginManager(pluginManager) {}

Chess* ChessFactory::createChessById(int id)
{
	//Refactored with Plugin Pattern
	// ����ʹ�ò����������������
	Chess* chess = this->pluginManager.createChessById(id); // ͨ�� this-> ���� pluginManager
	if (chess) {
		return chess; // �������������ɹ��������ӣ���ֱ�ӷ���
	}

	switch (id)
	{
	case 11:
		chess = Magikarp::create("Magikarp-right-1.png");
		break;
	case 12:
		chess = Buneary::create("Buneary-right-1.png");
		break;
	case 13:
		chess = Jingglypuff::create("Jigglypuff-right-1.png");
		break;

	case 21:
		chess = Yevee::create("Yevee-right-1.png");
		break;
	case 22:
		chess = Squirtle::create("Squirtle-right-1.png");
		break;
	case 23:
		chess = Charmander::create("Charmander-right-1.png");
		break;
	case 24:
		chess = Bulbasaur::create("Bulbasaur-right-1.png");
		break;
	case 25:
		chess = Pikachu::create("Pikachu-right-1.png");
		break;

	case 31:
		chess = Snorlax::create("Snorlax-right-1.png");
		break;
	case 32:
		chess = Mewtwo::create("Mewtwo-right-1.png");
		break;
	case 33:
		chess = Rugia::create("Rugia-right-1.png");
		break;
	default:
		chess = Chess::create(" ");
		break;
	}
	return chess;
}

