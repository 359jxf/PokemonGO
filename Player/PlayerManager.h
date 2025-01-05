#pragma once
#include "Player.h"
#include "PluginManager.h"
#include <vector>
#include <memory>
class PlayerManager
{
public:
    static PlayerManager* getInstance();

    void addPlayer(Player* player);//添加玩家

    Player* getPlayer(int index);//根据编号返回玩家信息

    //Refactored with Plugin Pattern
    // 插件管理器设置
    void setPluginManager(std::unique_ptr<PluginManager> pluginManager);
    PluginManager* getPluginManager();
private:
    std::vector<Player*> players;
    //Refactored with Plugin Pattern
    std::unique_ptr<PluginManager> pluginManager; // 插件管理器
};