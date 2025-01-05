//Refactored with Plugin Pattern
// ChessPlugin/PluginLoader.cpp
#include "PluginLoader.h"

PluginHandle PluginLoader::loadPlugin(const std::string& path) {
#ifdef _WIN32
    return LoadLibrary(path.c_str());
#else
    return dlopen(path.c_str(), RTLD_LAZY);
#endif
}

void* PluginLoader::getPluginFunction(PluginHandle handle, const std::string& functionName) {
#ifdef _WIN32
    return GetProcAddress(handle, functionName.c_str());
#else
    return dlsym(handle, functionName.c_str());
#endif
}

void PluginLoader::unloadPlugin(PluginHandle handle) {
#ifdef _WIN32
    FreeLibrary(handle);
#else
    dlclose(handle);
#endif
}