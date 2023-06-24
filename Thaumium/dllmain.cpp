// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "Core.h"

DWORD WINAPI MainThread(LPVOID lpReserved)
{
    bool hooked = false;
    while (!hooked)
    {
        Core::Init();
        hooked = true;
    }
    return TRUE;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        spdlog::info("Thaumium attached, hi :)");
        MH_Initialize();
        DisableThreadLibraryCalls(hModule);
        CreateThread(nullptr, 0, MainThread, hModule, 0, nullptr);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

