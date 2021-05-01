#ifndef ISCRIPTSYSTEM_H
#define ISCRIPTSYSTEM_H
#ifdef _WIN32
#pragma once
#endif

#include "appframework/IAppSystem.h"

/// <summary>
/// This is our interface for the script system
/// I don't know what to put in here for now
/// </summary>
class IScriptSystem : public IAppSystem
{
public:

	/// <summary>
	/// This is mostly for loading additional assemblies, not really for the end user
	/// </summary>
	/// <param name="assemblyPath">Path to the .NET assembly</param>
	virtual void LoadAssembly(char* assemblyPath) = 0;

	virtual bool PostInit() = 0;
};

extern IScriptSystem* scriptSystem;

#define SCRIPTSYSTEM_INTERFACE_VERSION "ScriptSystemVersion001"

#endif // !ISCRIPTSYSTEM_H
