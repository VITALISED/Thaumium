#include "pch.h"

DWORD WINAPI MainThread(LPVOID lpReserved)
{
    spdlog::info("Starting");
    ADDHOOK(OFFSET(0x2511EC0), RegisterHook, reinterpret_cast<LPVOID *>(&fpRegister), cTkMetaData::Register);

    std::ofstream PrimaryHeader("./HERIDIUM/metadata/metadata.h");

    PrimaryHeader << "#pragma once\n\n";
    for (int i = 0; i < classPaths.size(); i++)
    {
        PrimaryHeader << "#include \"";
        PrimaryHeader << classPaths[i].second;
        PrimaryHeader << "\"\n";
    }
    PrimaryHeader.close();

    return TRUE;
}

BOOL APIENTRY DllMain(HMODULE hModule,
                      DWORD ul_reason_for_call,
                      LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        AllocConsole();
        DisableThreadLibraryCalls(hModule);
        spdlog::set_level(spdlog::level::debug);
        MH_Initialize();
        CreateThread(nullptr, 0, MainThread, hModule, 0, nullptr);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}