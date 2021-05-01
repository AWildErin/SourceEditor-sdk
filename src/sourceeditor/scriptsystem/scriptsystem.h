#ifndef SCRIPTSYSTEM_H
#define SCRIPTSYSTEM_H
#ifdef _WIN32
#pragma once
#endif // _WIN32

#include "scriptsystem/iscriptsystem.h"
#include "tier1/tier1.h"

class CScriptSystem : public IScriptSystem
{
public:
	// Methods of IAppSystem
	virtual bool	Connect(CreateInterfaceFn factory);
	virtual void	Disconnect();

	// Returns null if it doesn't implement the requested interface
	virtual void* QueryInterface(const char* pIntefaceName);

	virtual InitReturnVal_t Init();
	virtual void	Shutdown();

public:
	// Methods of IScriptSystem
	virtual void	LoadAssembly(char* assemblyPath);
	virtual bool	PostInit();

private:
	void	LoadMono();
};

static CScriptSystem g_ScriptSystem;
IScriptSystem* scriptSystem = &g_ScriptSystem;

// Exposed because it's an IAppSystem
EXPOSE_SINGLE_INTERFACE_GLOBALVAR(CScriptSystem, IScriptSystem, SCRIPTSYSTEM_INTERFACE_VERSION, g_ScriptSystem);

#endif // !SCRIPTSYSTEM_H
