//======================================================//
//
// Purpose: Provides a sample tool for users to look at
// and learn how to make their own tool
//
//======================================================//

#include "editortoolframework/itool.h"
#include "tier1/interface.h"
#include "tier1/tier1.h"

class CToolZoo : public ITool
{
public:
	virtual bool Init();
	virtual void Shutdown();

	virtual void Think(bool finalTick);
};

bool CToolZoo::Init()
{
	Msg("ToolZoo::Init: Initalising tool\n");

	return true;
}

void CToolZoo::Shutdown()
{
	Msg("ToolZoo::Shutdown: Shutting down tool\n");
}

void CToolZoo::Think(bool finalTick)
{
}
