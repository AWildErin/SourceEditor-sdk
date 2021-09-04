#ifndef TOOLFRAMEWORK_H
#define TOOLFRAMEWORK_H
#ifdef _WIN32
#pragma once
#endif

#include "editortoolframework/ieditortoolframework.h"
#include "editortoolframework/itool.h"
#include "tier1/utlvector.h"
#include "tier1/tier1.h"

//class IToolSystem;

extern CreateInterfaceFn g_AppSystemFactory;

class CToolFramework : public IEditorToolFramework
{
public:
	// Methods of IAppSystem
	virtual bool	Connect(CreateInterfaceFn factory);
	virtual void	Disconnect();

	// Returns null if it doesn't implement the requested interface
	virtual void*	QueryInterface(const char* pIntefaceName);

	virtual InitReturnVal_t Init();
	virtual void	Shutdown();

public:
	// Methods of IEditorToolFramework
	virtual bool PostInit();
	virtual void Think(bool finalTick);

	virtual int GetToolCount();
	virtual char const* GetToolName(int index);

private:

	// Loads all the tools from our editor's tool folder
	void LoadTools();

	// Loads a specific tool if it was unloaded.
	// This is used mainly for StandaloneTool
	void LoadTool(const char* pDllName);

	// Shutdown/Unload all our tools
	void ShutdownTools();

	// Unloads/Shutdown a tool. This is called from our console
	// and is mainly added for tool development.
	void ShutdownTool(const char* pDllName);

	CUtlVector<ITool*> m_Tools;
	CUtlVector<CSysModule*> m_Modules;
};

static CToolFramework g_ToolFramework;
IEditorToolFramework* editorToolFramework = &g_ToolFramework;

// Exposed because it's an IAppSystem
EXPOSE_SINGLE_INTERFACE_GLOBALVAR(CToolFramework, IEditorToolFramework, EDTIORTOOLFRAMEWORK_INTERFACE_VERSION, g_ToolFramework);

#endif // !TOOLFRAMEWORK_H
