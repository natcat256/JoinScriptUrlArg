#pragma once

#include <oaidl.h>

// CWorkspace

class CWorkspace;
typedef HRESULT(__stdcall* CWorkspace__ExecUrlScript_t)(CWorkspace* workspace, BSTR url, VARIANTARG arg1, VARIANTARG arg2, VARIANTARG arg3, VARIANTARG arg4, LPSAFEARRAY*);
const auto CWorkspace__ExecUrlScript = reinterpret_cast<CWorkspace__ExecUrlScript_t>(0x0049FEC0);

// CRobloxDoc

class CRobloxDoc
{
private:
	void* padding1[49];
public:
	CWorkspace* workspace;
};

// CWinApp

class CWinApp;

typedef int(__thiscall* CWinApp__DoMessageBox_t)(CWinApp* _this, LPCTSTR lpszPrompt, UINT nType, UINT nIDPrompt);
const auto CWinApp__DoMessageBox = reinterpret_cast<CWinApp__DoMessageBox_t>(0x007E0C0A);

// CRobloxApp

class CRobloxApp;

typedef BOOL(__thiscall* CRobloxApp__InitInstance_t)(CRobloxApp* _this);
extern CRobloxApp__InitInstance_t CRobloxApp__InitInstance;
BOOL __fastcall CRobloxApp__InitInstance_hook(CRobloxApp* _this);

typedef CRobloxDoc* (__thiscall* CRobloxApp__CreateDocument_t)(CRobloxApp* _this);
const auto CRobloxApp__CreateDocument = reinterpret_cast<CRobloxApp__CreateDocument_t>(0x004603A0);

// CCommandLineInfo

class CCommandLineInfo;

typedef void(__thiscall* CCommandLineInfo__ParseLast_t)(CCommandLineInfo* _this, BOOL bLast);
const auto CCommandLineInfo__ParseLast = reinterpret_cast<CCommandLineInfo__ParseLast_t>(0x007E0C4C);

// CRobloxCommandLineInfo

class CRobloxCommandLineInfo
{
private:
	void* padding1[3];
public:
	BOOL m_bRunAutomated;
};

typedef void(__thiscall* CRobloxCommandLineInfo__ParseParam_t)(CRobloxCommandLineInfo* _this, const TCHAR* pszParam, BOOL bFlag, BOOL bLast);
extern CRobloxCommandLineInfo__ParseParam_t CRobloxCommandLineInfo__ParseParam;
void __fastcall CRobloxCommandLineInfo__ParseParam_hook(CRobloxCommandLineInfo* _this, void*, const TCHAR* pszParam, BOOL bFlag, BOOL bLast);

