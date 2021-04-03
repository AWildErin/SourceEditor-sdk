#include "toolframework.h"
#include "tier0/icommandline.h"
#include "tier1/KeyValues.h"
#include "tier1/tier1.h"
#include "filesystem.h"

IBaseFileSystem* g_pFileSystem;

bool CToolFramework::Connect(CreateInterfaceFn factory)
{
	g_pFileSystem = (IBaseFileSystem*)factory(BASEFILESYSTEM_INTERFACE_VERSION, NULL);

	if (!g_pFileSystem)
	{
		Msg("Tool Framework: Failed to connect\n");
		return false;
	}

	Msg("Tool Framework: Connected uccessfully\n");
	return true;
}

void CToolFramework::Disconnect()
{
}

void* CToolFramework::QueryInterface(const char* pIntefaceName)
{
	return nullptr;
}

InitReturnVal_t CToolFramework::Init()
{
	LoadTools();

	return INIT_OK;
}

void CToolFramework::Shutdown()
{
	g_pFileSystem = nullptr;

	ShutdownTools();
}

bool CToolFramework::PostInit()
{
	return false;
}

void CToolFramework::Think(bool finalTick)
{
}

int CToolFramework::GetToolCount()
{
	return 0;
}

char const* CToolFramework::GetToolName(int index)
{
	return nullptr;
}

#pragma region Load Tools

void CToolFramework::LoadTools()
{
	Msg("Loading all the tools\n");
	for (int i = 1; i < 10; i++)
	{
		Msg("Loading tool: %i\n", i);
	}
}

void CToolFramework::LoadTool(const char* pDllName)
{
}

void ToolLoad_F(const CCommand& args)
{

}
static ConCommand ToolLoad("toolload", ToolLoad_F, "Load a specific tool", 0);
// CSGO uses g_ToolLoad_CompletionFunc, I'm unsure what exactly this is.

#pragma endregion

#pragma region Shutdown Tools

void CToolFramework::ShutdownTools()
{
}

void CToolFramework::ShutdownTool(const char* pDllName)
{
}

void ToolUnload_F(const CCommand& args)
{

}
static ConCommand ToolUnload("toolunload", ToolUnload_F, "Unload a specific tool", 0);

#pragma endregion