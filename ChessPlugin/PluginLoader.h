// Refactored with Plugin Pattern
// ChessPlugin/PluginLoader.h
#ifndef PLUGINLOADER_H
#define PLUGINLOADER_H

#ifdef _WIN32
#include <windows.h>
using PluginHandle = HMODULE; // Windows 平台使用 HMODULE 表示插件句柄
#else
#include <dlfcn.h>
using PluginHandle = void*; // 非 Windows 平台使用 void* 表示插件句柄
#endif

class PluginLoader {
public:
    // 加载插件
    PluginHandle loadPlugin(const std::string& path);

    // 获取插件中的函数
    void* getPluginFunction(PluginHandle handle, const std::string& functionName);

    // 卸载插件
    void unloadPlugin(PluginHandle handle);
};

#endif // PLUGINLOADER_H