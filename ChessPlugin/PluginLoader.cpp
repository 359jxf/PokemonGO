// Refactored with Plugin Pattern
// ChessPlugin/PluginLoader.cpp
#include "PluginLoader.h"

// 加载插件
PluginHandle PluginLoader::loadPlugin(const std::string& path) {
#ifdef _WIN32
    return LoadLibrary(path.c_str()); // Windows 平台加载 DLL
#else
    return dlopen(path.c_str(), RTLD_LAZY); // 非 Windows 平台加载 SO 或 DYLIB
#endif
}

// 获取插件中的函数
void* PluginLoader::getPluginFunction(PluginHandle handle, const std::string& functionName) {
#ifdef _WIN32
    return GetProcAddress(handle, functionName.c_str()); // Windows 平台获取函数指针
#else
    return dlsym(handle, functionName.c_str()); // 非 Windows 平台获取函数指针
#endif
}

// 卸载插件
void PluginLoader::unloadPlugin(PluginHandle handle) {
#ifdef _WIN32
    FreeLibrary(handle); // Windows 平台卸载 DLL
#else
    dlclose(handle); // 非 Windows 平台卸载 SO 或 DYLIB
#endif
}