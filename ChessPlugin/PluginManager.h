// Refactored with Plugin Pattern
// ChessPlugin/PluginManager.h
#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include <unordered_map>
#include <string>
#include <memory>
#include "ChessPlugin.h" // ��������ӿ�

class PluginManager {
public:
    // ע����
    void registerChessPlugin(std::unique_ptr<ChessPlugin> plugin);

    // ���� ID ��������
    Chess* createChessById(int id);

private:
    std::unordered_map<int, std::unique_ptr<ChessPlugin>> idToPluginMap; // ID �������ӳ��
};

#endif // PLUGINMANAGER_H