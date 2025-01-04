// Refactored with Plugin Pattern
// ChessPlugin/PluginManager.cpp
#include "PluginManager.h"
#include "Chess.h"

// ע����
void PluginManager::registerChessPlugin(std::unique_ptr<ChessPlugin> plugin) {
    int id = plugin->getId();
    idToPluginMap[id] = std::move(plugin); // ������洢��ӳ����
}

// ���� ID ��������
Chess* PluginManager::createChessById(int id) {
    if (idToPluginMap.find(id) != idToPluginMap.end()) {
        return idToPluginMap[id]->createChess(); // ���ò���Ĵ�������
    }
    return nullptr; // ���δ�ҵ���������ؿ�ָ��
}