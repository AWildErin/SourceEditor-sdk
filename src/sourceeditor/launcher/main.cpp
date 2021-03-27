#include "appframework/tier3app.h"
#include "tier0/icommandline.h"
#include "inputsystem/iinputsystem.h"

#include <io.h>
#include <stdio.h>

#include <winsock2.h>
#include "steam/steam_api.h"

// memdbgon must be the last include file in a .cpp file!!!
#include <tier0/memdbgon.h>

CSteamAPIContext g_SteamAPIContext;
CSteamAPIContext* steamapicontext = &g_SteamAPIContext;

bool g_bAppQuit = false;

void ShutdownMessageWindow(void)
{

}

int InitializeVGui()
{

}

void CheckConfigParameters()
{
	// Shader API parameter, allows the user to change what shader API we use
	const char* pShaderDLL(CommandLine()->ParmValue("-shaderdll"));
	const char* pArg;

	if (CommandLine()->CheckParm("-shaderapi", &pArg))
	{
		pShaderDLL = pArg;
	}

	if (!pShaderDLL)
	{
		pShaderDLL = "shaderapidx9.dll";
	}

	// Call SetShaderAPI when we can
}

//-----------------------------------------------------------------------------
// The application object
//-----------------------------------------------------------------------------
class CSourceEditorApp : public CVguiSteamApp
{
	typedef CVguiSteamApp BaseClass;

public:
	// Methods from IApplication
	virtual bool Create();
	virtual bool PreInit();
	virtual int Main();
	virtual void PostShutdown();
	virtual void Destroy() {}
};

DEFINE_WINDOWED_STEAM_APPLICATION_OBJECT(CSourceEditorApp);

/*
	TODO: Add things like material system here too to be able to access Source's renderer.
	TODO: Add command to allow us to define a shader api
*/
bool CSourceEditorApp::Create()
{
	//SpewOutputFunc();

	// List of DLLs we require
	AppSystemInfo_t appSystems[] =
	{
		{ "inputsystem.dll",		INPUTSYSTEM_INTERFACE_VERSION },
		{ "", "" }	// Required to terminate the list
	};

	// Add the DLLs above
	return AddSystems(appSystems);
}

bool CSourceEditorApp::PreInit()
{
	return false;
}

int CSourceEditorApp::Main()
{
	SteamAPI_InitSafe();
	SteamAPI_SetTryCatchCallbacks(false); // We don't use exceptions, so tell steam not to use try/catch in callback handlers
	g_SteamAPIContext.Init();

	return 1;
}

void CSourceEditorApp::PostShutdown()
{
	BaseClass::PostShutdown();
}
