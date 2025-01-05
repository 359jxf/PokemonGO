// Refactored with Plugin Pattern
// ChessPlugin/PluginLoader.h
#ifndef PLUGINLOADER_H
#define PLUGINLOADER_H

#ifdef _WIN32
#include <windows.h>
using PluginHandle = HMODULE; // Windows ƽ̨ʹ�� HMODULE ��ʾ������
#else
#include <dlfcn.h>
using PluginHandle = void*; // �� Windows ƽ̨ʹ�� void* ��ʾ������
#endif

class PluginLoader {
public:
    // ���ز��
    PluginHandle loadPlugin(const std::string& path);

    // ��ȡ����еĺ���
    void* getPluginFunction(PluginHandle handle, const std::string& functionName);

    // ж�ز��
    void unloadPlugin(PluginHandle handle);
};

#endif // PLUGINLOADER_H