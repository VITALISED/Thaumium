// dllmain.cpp : Defines the entry point for the DLL application.
#include "dllmain.h"
#include "pch.h"

DWORD WINAPI MainThread(LPVOID lpReserved)
{
    Core::Initialise();

    return TRUE;
}

BOOL APIENTRY DllMain(HMODULE hModule,
                      DWORD ul_reason_for_call,
                      LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);
        spdlog::set_level(spdlog::level::debug);
        spdlog::info("Thaumium running on build: {}", THAUMIUM_VER);
        MH_Initialize();
        CreateThread(nullptr, 0, MainThread, hModule, 0, nullptr);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
