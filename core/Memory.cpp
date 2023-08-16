#include "memory.h"

void Memory::PatchBytes(uintptr_t ptr, uint8_t bytes[])
{
    DWORD oldprotection, newprotection;
    VirtualProtect((LPVOID)ptr, 1, PAGE_EXECUTE_READWRITE, &oldprotection);
    memcpy((void*)ptr, (char*)bytes, sizeof(bytes));
    VirtualProtect((LPVOID)ptr, 1, oldprotection, &newprotection);
}

std::vector<int> Memory::IdaPatternToByte(const char* sig)
{
    std::vector<int> bytes = std::vector<int>();

    char* cast = const_cast<char*>(sig);
    char* end = const_cast<char*>(sig) + std::strlen(sig);

    for (char* current = cast; current < end; ++current)
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

uintptr_t Memory::ScanPattern(std::vector<int> pattern) {
    const HMODULE module_handle = GetModuleHandleA(NULL);

    if (!module_handle)
        return (uintptr_t)nullptr;

    PIMAGE_DOS_HEADER dos_header = reinterpret_cast<PIMAGE_DOS_HEADER>(module_handle);
    PIMAGE_NT_HEADERS nt_headers =
        reinterpret_cast<PIMAGE_NT_HEADERS>(reinterpret_cast<std::uint8_t*>(module_handle) + dos_header->e_lfanew);

    DWORD size_of_image = nt_headers->OptionalHeader.SizeOfImage;
    std::vector<int> pattern_bytes = pattern;
    uint8_t* scan_bytes = reinterpret_cast<std::uint8_t*>(module_handle);

    int s = pattern_bytes.size();
    int* d = pattern_bytes.data();

    for (long i = 0ul; i < size_of_image - s; ++i) {
        bool found = true;

        for (long j = 0ul; j < s; ++j) {
            if (scan_bytes[i + j] != d[j] && d[j] != -1) {
                found = false;
                break;
            }
        }
        if (found)
            return (uintptr_t)&scan_bytes[i];
    }

    return (uintptr_t)nullptr;
}