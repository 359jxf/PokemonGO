// Refactored with Plugin Pattern
// ChessPlugin/PluginManager.h
#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include <unordered_map>
#include <string>
#include <memory>
#include "ChessPlugin.h" // 包含插件接口

class PluginManager {
public:
    // 注册插件
    void registerChessPlugin(std::unique_ptr<ChessPlugin> plugin);

    // 根据 ID 创建棋子
    Chess* createChessById(int id);

private:
    std::unordered_map<int, std::unique_ptr<ChessPlugin>> idToPluginMap; // ID 到插件的映射
};

#endif // PLUGINMANAGER_H