#ifndef MEMORY_H
#define MEMORY_H
#include <windows.h>
#include <tlhelp32.h>
#include <tchar.h>
#include <stdio.h>
#include <cstdio>
#include <cstring>

class Memory {
public:
    Memory();
    void assignProcess();
    DWORD getModule(char* ModuleName);
    void read(DWORD address, DWORD &value);
private:
    DWORD processId;
    HANDLE hProcess;
    HWND hwnd;
};

#endif // MEMORY_H
