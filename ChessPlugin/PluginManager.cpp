//Refactored with Plugin Pattern
// ChessPlugin/PluginManager.cpp
#include "PluginManager.h"
#include "Chess.h"

void PluginManager::registerChessPlugin(std::unique_ptr<ChessPlugin> plugin) {
    int id = plugin->getId();
    idToPluginMap[id] = std::move(plugin); // ע����
}

Chess* PluginManager::createChessById(int id) {
    if (idToPluginMap.find(id) != idToPluginMap.end()) {
        return idToPluginMap[id]->createChess(); // ���ò���Ĵ�������
    }
    return nullptr;
}

// ���� ID ��ȡ���
ChessPlugin* PluginManager::getPluginById(int id) {
    if (idToPluginMap.find(id) != idToPluginMap.end()) {
        return idToPluginMap[id].get();
    }
    return nullptr;
}
