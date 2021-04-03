#ifndef ITOOL_H
#ifdef _WIN32
#pragma once
#endif

#include "interface.h"


/// <summary>
/// Purpose: All tools expose this interface which has hooks for them to use.
/// </summary>
class ITool
{
	// Todo: Add more hooks than just init, think and shutdown

public:

	// Called when the tool gets loaded
	virtual bool Init() = 0;

	// Called when the tool is unloaded or when the editor is shutdown.
	virtual void Shutdown() = 0;

	// Called once per frame
	virtual void Think(bool finalTick) = 0;
};

#endif // !ITOOL_H
