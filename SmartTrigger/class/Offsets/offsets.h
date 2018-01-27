#ifndef OFFSETS_H
#define OFFSETS_H

#include <windows.h>

class Offsets {
    Offsets();
    public:
        // requires client.dll
        DWORD playerBase = 0xA9D0DC;
        DWORD entBase = 0x04A79EC4;

        // requires player or ent
        DWORD team = 0xF0;
        DWORD crosshair = 0xB2A4;
};

#endif // OFFSETS_H


