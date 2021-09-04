#ifndef TOOLDICTIONARY_H
#define TOOLDICTIONARY_H
#ifdef _WIN32
#pragma once
#endif

#include "editortoolframework/ieditortooldictionary.h"
#include "editortoolframework/ieditortoolframework.h"
#include "editortoolframework/itool.h"
#include "tier3/tier3dm.h"
#include "filesystem.h"

class CToolDictionary : public CTier3DmAppSystem<IEditorToolDictionary>
{
	typedef CTier3DmAppSystem<IEditorToolDictionary> BaseClass;
public:
	CToolDictionary();

	// IAppSystem methods
	virtual bool Connect(CreateInterfaceFn factory);
	virtual void Disconnect();
	virtual void* QueryInterface(const char* pInterfaceName);
	virtual InitReturnVal_t Init();
	virtual void Shutdown();


	// IEditorToolDictionary methods
	virtual void CreateTool();
};

static CToolDictionary g_EditorToolDictionary;
EXPOSE_SINGLE_INTERFACE_GLOBALVAR(CToolDictionary, IEditorToolDictionary, EDITORTOOLDICTIONARY_INTERFACE_VERSION, g_EditorToolDictionary);

#endif // !TOOLDICTIONARY_H
