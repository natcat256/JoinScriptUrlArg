#include "pch.h"
#include "JoinScriptUrlArg.h"

#include <string>
#include <stdexcept>

CRobloxApp__InitInstance_t CRobloxApp__InitInstance = reinterpret_cast<CRobloxApp__InitInstance_t>(0x00464550);

static std::wstring joinScriptUrl;

BOOL __fastcall CRobloxApp__InitInstance_hook(CRobloxApp* _this)
{
    if (!CRobloxApp__InitInstance(_this))
        return FALSE;

    if (!joinScriptUrl.empty())
    {
        try
        {
            CRobloxDoc* document = CRobloxApp__CreateDocument(_this);
            CWorkspace__ExecUrlScript(document->workspace, &joinScriptUrl[0], VARIANTARG(), VARIANTARG(), VARIANTARG(), VARIANTARG(), nullptr);
        }
        catch (std::runtime_error& error)
        {
            CWinApp__DoMessageBox(reinterpret_cast<CWinApp*>(_this), error.what(), MB_ICONERROR | MB_SETFOREGROUND, 0);
            return FALSE;
        }
    }

    return TRUE;
}

CRobloxCommandLineInfo__ParseParam_t CRobloxCommandLineInfo__ParseParam = reinterpret_cast<CRobloxCommandLineInfo__ParseParam_t>(0x004625B0);

void __fastcall CRobloxCommandLineInfo__ParseParam_hook(CRobloxCommandLineInfo* _this, void*, const TCHAR* pszParam, BOOL bFlag, BOOL bLast)
{
    static bool argWasLast = false;

    if (argWasLast && !bFlag)
    {
        int size = MultiByteToWideChar(CP_ACP, 0, pszParam, strlen(pszParam), nullptr, 0);
        joinScriptUrl.resize(size);
        MultiByteToWideChar(CP_ACP, 0, pszParam, strlen(pszParam), &joinScriptUrl[0], size);

        _this->m_bRunAutomated = TRUE;

        CCommandLineInfo__ParseLast(reinterpret_cast<CCommandLineInfo*>(_this), bLast);
        return;
    }

    argWasLast = false;

    if (bFlag && _stricmp(pszParam, "JoinScriptUrl") == 0)
    {
        argWasLast = true;

        CCommandLineInfo__ParseLast(reinterpret_cast<CCommandLineInfo*>(_this), bLast);
        return;
    }

    CRobloxCommandLineInfo__ParseParam(_this, pszParam, bFlag, bLast);
}
