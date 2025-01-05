#include "PlayerManager.h"

PlayerManager* PlayerManager::getInstance()
{
    static PlayerManager instance;
    return &instance;
}

void PlayerManager::addPlayer(Player* player)
{

    players.push_back(player);

}

Player* PlayerManager::getPlayer(int index)
{
    if (index >= 0 && index < players.size()) {

        return players[index];
    }
    return nullptr;
}

//Refactored with Plugin Pattern
// 设置插件管理器
void PlayerManager::setPluginManager(std::unique_ptr<PluginManager> pluginManager)
{
    this->pluginManager = std::move(pluginManager);
}

//Refactored with Plugin Pattern
// 获取插件管理器
PluginManager* PlayerManager::getPluginManager()
{
    return pluginManager.get();
}
