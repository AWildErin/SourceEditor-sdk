#include "toolframework.h"
#include "tier0/icommandline.h"
#include "tier1/KeyValues.h"
#include "tier1/tier1.h"
#include "filesystem.h"

IFileSystem* g_pFileSystem;

bool CToolFramework::Connect(CreateInterfaceFn factory)
{
	//g_pFileSystem = (IBaseFileSystem*)factory(BASEFILESYSTEM_INTERFACE_VERSION, NULL);
	g_pFileSystem = (IFileSystem*)factory(FILESYSTEM_INTERFACE_VERSION, NULL);

	if (!g_pFileSystem)
	{
		Msg("Tool Framework: Failed to connect\n");
		return false;
	}

	Msg("Tool Framework: Connected successfully\n");
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

	FileFindHandle_t fileHandle;
	const char* pFilename = g_pFileSystem->FindFirstEx("../tools/*.*", "EXECUTABLE_PATH", &fileHandle);

	while (pFilename)
	{
		if (V_stricmp(pFilename, ".") != 0 && V_stricmp(pFilename, "..") != 0)
		{
			if (g_pFileSystem->FindIsDirectory(fileHandle))
			{
				KeyValues* toolData = new KeyValues("tooldata");

				char toolDataPath[MAX_PATH];
				V_snprintf(toolDataPath, sizeof(toolDataPath), "../tools/%s/tool.vdf", pFilename);

				if( toolData && toolData->LoadFromFile(g_pFileSystem, toolDataPath, "EXECUTABLE_PATH"))
				{
					for (KeyValues* tool = toolData->GetFirstSubKey();
						tool != NULL;
						tool = tool->GetNextKey())
					{
						Msg("Tool Framework: %s\n", tool->GetString("m_Name"));
						Msg("Tool Framework: %s\n", tool->GetString("m_FriendlyName"));
					}
					toolData->deleteThis();
				}

			}
		}

		pFilename = g_pFileSystem->FindNext(fileHandle);
	}
	g_pFileSystem->FindClose(fileHandle);

	/*
	KeyValues* toolData = new KeyValues("tooldata");
	char* testFilePath = "../tools/hammer/tool.vdf";

	if (toolData && toolData->LoadFromFile(g_pFileSystem, testFilePath, "EXECUTABLE_PATH"))
	{
		for (KeyValues* tool = toolData->GetFirstSubKey();
			tool != NULL;
			tool = tool->GetNextKey())
		{
			Msg("Tool Framework: %s\n", tool->GetString("m_Name"));
			Msg("Tool Framework: %s\n", tool->GetString("m_FriendlyName"));
		}
	}
	*/
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