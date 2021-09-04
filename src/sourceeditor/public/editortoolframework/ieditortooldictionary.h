#ifndef IEDITORTOOLDICTIONARY_H
#define IEDITORTOOLDICTIONARY_H
#ifdef _WIN32
#pragma once
#endif

#include "appframework/IAppSystem.h"
#include "itool.h"

// Forward declaration
class ITool;

class IEditorToolDictionary : public IAppSystem
{
public:
	virtual void CreateTool() = 0;
};

#define EDITORTOOLDICTIONARY_INTERFACE_VERSION "EditorToolDictionaryVersion001"

#endif // !IEDITORTOOLDICTIONARY_H
