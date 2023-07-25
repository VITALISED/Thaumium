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
        if (*current == '?')
        {
            ++current;

            if (*current == '?')
                ++current;

            bytes.push_back(-1);
        }
        else
        {
            bytes.push_back(std::strtoul(current, &current, 16));
        }
    }

    return bytes;
}

uintptr_t Memory::ScanPattern(std::vector<BYTE> pattern)
{
    HMODULE hmodule = (HMODULE)_BASE;

    PIMAGE_DOS_HEADER dosHeader = (PIMAGE_DOS_HEADER)hmodule;
    PIMAGE_NT_HEADERS ntHeaders = (PIMAGE_NT_HEADERS)((std::uint8_t*)hmodule + dosHeader->e_lfanew);

    DWORD sizeOfImage = ntHeaders->OptionalHeader.SizeOfImage;
    std::uint8_t* scanBytes = reinterpret_cast<std::uint8_t*>(hmodule);

    size_t s = pattern.size();
    BYTE* d = pattern.data();

    for (long i = 0ul; i < sizeOfImage - s; ++i)
    {
        bool found = true;
        for (long j = 0ul; j < s; ++j)
        {
            if (scanBytes[i + j] != d[j] && d[j] != -1)
            {
                found = false;
                break;
            }
        }
        if (found)
        {
            return (uintptr_t)&scanBytes[i];
        }
    }
    return (uintptr_t)nullptr;
}
