// Refactored with Plugin Pattern
// ChessPlugin/PluginManager.cpp
#include "PluginManager.h"
#include "Chess.h"

// 注册插件
void PluginManager::registerChessPlugin(std::unique_ptr<ChessPlugin> plugin) {
    int id = plugin->getId();
    idToPluginMap[id] = std::move(plugin); // 将插件存储在映射中
}

// 根据 ID 创建棋子
Chess* PluginManager::createChessById(int id) {
    if (idToPluginMap.find(id) != idToPluginMap.end()) {
        return idToPluginMap[id]->createChess(); // 调用插件的创建函数
    }
    return nullptr; // 如果未找到插件，返回空指针
}