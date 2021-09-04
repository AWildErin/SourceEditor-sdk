#include "scriptsystem.h"
#include "tier0/icommandline.h"
#include "tier1/tier1.h"
#include "filesystem.h"
#include "tier0/icommandline.h"

// Mono
#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/debug-helpers.h>

IFileSystem* g_pFileSystem;

bool CScriptSystem::Connect(CreateInterfaceFn factory)
{
	g_pFileSystem = (IFileSystem*)factory(FILESYSTEM_INTERFACE_VERSION, NULL);

	if (!g_pFileSystem)
	{
		Msg("Script System: Failed to connect\n");
		return false;
	}

	Msg("Script System: Connected successfully\n");

    return true;
}

void CScriptSystem::Disconnect()
{
}

void* CScriptSystem::QueryInterface(const char* pInterfaceName)
{
	CreateInterfaceFn factory = Sys_GetFactoryThis();
	return factory( pInterfaceName, NULL );
}

InitReturnVal_t CScriptSystem::Init()
{
	// load and init the mono runtime
	LoadMono();

    return INIT_OK;
}

void CScriptSystem::Shutdown()
{
    g_pFileSystem = nullptr;
}

void CScriptSystem::LoadAssembly(char* assemblyPath)
{
}

bool CScriptSystem::PostInit()
{
    return true;
}

void CScriptSystem::LoadMono()
{
#pragma region Init mono runtime

	mono_set_dirs("C:\\Program Files (x86)\\Mono\\lib",
		"C:\\Program Files (x86)\\Mono\\etc");

	// Init a domain
	MonoDomain* domain;
	domain = mono_jit_init("ScriptSystem");
	if (!domain)
	{
		Warning("Script System: mono_jit_init failed\n");
		return;
	}

	// Open an assembly in the domain
	MonoAssembly* assembly;
	char* assemblyPath = "E:/Repositories/Source-Engine-Related/SourceEditor-sdk/game/sourceeditor/bin/managed/TestClass.dll";
	assembly = mono_domain_assembly_open(domain, assemblyPath);
	if (!assembly)
	{
		Warning("Script System: mono_domain_assembly_open failed\n");
		return;
	}

	// Get an image from the assembly
	MonoImage* image;
	image = mono_assembly_get_image(assembly);
	if (!image)
	{
		Warning("Script System: mono_assembly_get_image failed\n");
		return;
	}

#pragma endregion

#pragma region Run a static method
	
	// Build a method description object
	MonoMethodDesc* TypeMethodDesc;
	char* TypeMethodDescStr = "TestClass:TestBindings()";
	TypeMethodDesc = mono_method_desc_new(TypeMethodDescStr, NULL);
	if (!TypeMethodDesc)
	{
		Warning("Script System: mono_method_desc_new failed\n");
		return;
	}

	//Search the method in the image
	MonoMethod* method;
	method = mono_method_desc_search_in_image(TypeMethodDesc, image);
	if (!method)
	{
		Warning("Script System: mono_method_desc_search_in_image failed\n");
		return;
	}

	// Run the method
	Msg( "Running the static method: %s\n", TypeMethodDescStr );
	mono_runtime_invoke( method, nullptr, nullptr, nullptr );
#pragma endregion
}