#include "memory.h"

void Memory::PatchBytes(uintptr_t ptr, const char* sig)
{
    std::vector<BYTE> bytesVec = IdaPatternToByte(sig);

    DWORD oldprotection, newprotection;
    VirtualProtect((LPVOID)ptr, 1, PAGE_EXECUTE_READWRITE, &oldprotection);

    for (int i = 0; i < 10; i++)
    {
        uint8_t val = bytesVec[i];
        uint8_t* code = (uint8_t*)ptr+i;
        *code = val;
    }

    VirtualProtect((LPVOID)ptr, 1, oldprotection, &newprotection);
}

std::vector<BYTE> Memory::IdaPatternToByte(const char* sig)
{
    std::vector<BYTE> bytes = std::vector<BYTE>();

    auto cast = const_cast<char*>(sig);
    auto end = const_cast<char*>(sig) + std::strlen(sig);

    for (auto current = cast; current < end; ++current)
    {
        if (*current == '?') {
            ++current;

            if (*current == '?')
                ++current;

            bytes.push_back(-1);
        }
        else {
            bytes.push_back(std::strtoul(current, &current, 16));
        }
    }

    return bytes;
}

uintptr_t Memory::NMSMalloc(long size)
{
    cTkMemoryManager::Malloc nmsMalloc = (cTkMemoryManager::Malloc)OFFSET(0x2EDE470);
    return (uintptr_t)nmsMalloc(TKMEMORYMANAGER, size, "kill", 69, "too lazy", 16, -1);
}