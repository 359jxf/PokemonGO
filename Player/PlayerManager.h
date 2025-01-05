#pragma once
#include "Player.h"
#include "PluginManager.h"
#include <vector>
#include <memory>
class PlayerManager
{
public:
    static PlayerManager* getInstance();

    void addPlayer(Player* player);//������

    Player* getPlayer(int index);//���ݱ�ŷ��������Ϣ

    //Refactored with Plugin Pattern
    // �������������
    void setPluginManager(std::unique_ptr<PluginManager> pluginManager);
    PluginManager* getPluginManager();
private:
    std::vector<Player*> players;
    //Refactored with Plugin Pattern
    std::unique_ptr<PluginManager> pluginManager; // ���������
};