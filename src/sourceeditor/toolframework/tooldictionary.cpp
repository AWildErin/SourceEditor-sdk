#include "tooldictionary.h"

CToolDictionary::CToolDictionary()
{
}

bool CToolDictionary::Connect(CreateInterfaceFn factory)
{
	if (!BaseClass::Connect(factory))
		return false;

	return true;
}

void CToolDictionary::Disconnect()
{
}

void* CToolDictionary::QueryInterface(const char* pInterfaceName)
{
	return nullptr;
}

InitReturnVal_t CToolDictionary::Init()
{
	InitReturnVal_t nRetVal = BaseClass::Init();
	if (nRetVal != INIT_OK)
		return nRetVal;

	return INIT_OK;
}

void CToolDictionary::Shutdown()
{
	BaseClass::Disconnect();
}

void CToolDictionary::CreateTool()
{
	//::CreateTool();
}
