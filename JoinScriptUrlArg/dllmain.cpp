#include "pch.h"
#include "JoinScriptUrlArg.h"

#include <detours.h>

// imports table should be patched to include this function, forcing this dll to be loaded
void __declspec(dllexport) attachment() {}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        DetourTransactionBegin();

        DetourAttach(reinterpret_cast<LPVOID*>(&CRobloxApp__InitInstance), CRobloxApp__InitInstance_hook);
        DetourAttach(reinterpret_cast<LPVOID*>(&CRobloxCommandLineInfo__ParseParam), CRobloxCommandLineInfo__ParseParam_hook);

        DetourTransactionCommit();
    }

    return TRUE;
}
