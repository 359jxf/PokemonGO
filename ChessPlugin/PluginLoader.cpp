// Refactored with Plugin Pattern
// ChessPlugin/PluginLoader.cpp
#include "PluginLoader.h"

// ���ز��
PluginHandle PluginLoader::loadPlugin(const std::string& path) {
#ifdef _WIN32
    return LoadLibrary(path.c_str()); // Windows ƽ̨���� DLL
#else
    return dlopen(path.c_str(), RTLD_LAZY); // �� Windows ƽ̨���� SO �� DYLIB
#endif
}

// ��ȡ����еĺ���
void* PluginLoader::getPluginFunction(PluginHandle handle, const std::string& functionName) {
#ifdef _WIN32
    return GetProcAddress(handle, functionName.c_str()); // Windows ƽ̨��ȡ����ָ��
#else
    return dlsym(handle, functionName.c_str()); // �� Windows ƽ̨��ȡ����ָ��
#endif
}

// ж�ز��
void PluginLoader::unloadPlugin(PluginHandle handle) {
#ifdef _WIN32
    FreeLibrary(handle); // Windows ƽ̨ж�� DLL
#else
    dlclose(handle); // �� Windows ƽ̨ж�� SO �� DYLIB
#endif
}