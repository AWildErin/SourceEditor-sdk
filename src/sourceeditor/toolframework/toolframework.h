#ifndef TOOLFRAMEWORK_H
#define TOOLFRAMEWORK_H
#ifdef _WIN32
#pragma once
#endif

#include "editortoolframework/ieditortoolframework.h"

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
	virtual void Tink(bool finalTick);

	virtual int GetToolCount();
	virtual const char* GetToolName();

private:

	// Loads all the tools from our editor's tool folder
	void LoadTools();

	// Loads a specific tool if it was unloaded.
	// This is used mainly for StandaloneTool
	void LoadTool(const char* pDllName);

	// Shutsdown all our tools
	void ShutdownTools();

	// Unloads/Shutdown a tool. This is called from our console
	// and is mainly added for tool development.
	void ShutdownTool(const char* pDllName);

};

#endif // !TOOLFRAMEWORK_H
