#ifndef IEDITORTOOLFRAMEWORK_H
#define IEDITORTOOLFRAMEWORK_H
#ifdef _WIN32
#pragma once
#endif

#include "appframework/IAppSystem.h"

class IEditorToolFramework : public IAppSystem
{
public:
	// Other Hooks
	virtual bool PostInit() = 0;
	virtual void Think(bool finalTick) = 0;

public:
	// General hooks
	virtual int			GetToolCount() = 0;
	virtual const char* GetToolName(int index) = 0;
};

// Expose to the rest of the engine
extern IEditorToolFramework* editorToolFramework;

// Exposed for the AppSystemGroup hooks
#define EDTIORTOOLFRAMEWORK_INTERFACE_VERSION	"EDITORTOOLFRAMEWORKVERSION001"

#endif // IEDITORTOOLFRAMEWORK_H