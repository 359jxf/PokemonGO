//Refactored with Plugin Pattern
// ChessPlugin/PluginLoader.h
#ifndef PLUGINLOADER_H
#define PLUGINLOADER_H

#ifdef _WIN32
#include <windows.h>
using PluginHandle = HMODULE;
#else
#include <dlfcn.h>
using PluginHandle = void*;
#endif

class PluginLoader {
public:
    PluginHandle loadPlugin(const std::string& path);
    void* getPluginFunction(PluginHandle handle, const std::string& functionName);
    void unloadPlugin(PluginHandle handle);
};

#endif // PLUGINLOADER_H