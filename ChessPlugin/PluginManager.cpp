//Refactored with Plugin Pattern
// ChessPlugin/PluginManager.cpp
#include "PluginManager.h"
#include "Chess.h"

void PluginManager::registerChessPlugin(std::unique_ptr<ChessPlugin> plugin) {
    int id = plugin->getId();
    idToPluginMap[id] = std::move(plugin); // 注册插件
}

Chess* PluginManager::createChessById(int id) {
    if (idToPluginMap.find(id) != idToPluginMap.end()) {
        return idToPluginMap[id]->createChess(); // 调用插件的创建函数
    }
    return nullptr;
}

// 根据 ID 获取插件
ChessPlugin* PluginManager::getPluginById(int id) {
    if (idToPluginMap.find(id) != idToPluginMap.end()) {
        return idToPluginMap[id].get();
    }
    return nullptr;
}
