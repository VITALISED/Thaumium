#include "core.h"

std::vector<cTkClassPointer> gvDefinedMetadata;

void Core::Init()
{
	cEgModules::Initialise();
	gvDefinedMetadata = std::vector<cTkClassPointer>();

	TextChatHandler::Init();
	NGuiMBINExport::Init();
	//FIXME: 
	//FrontendOptions::Init(); 
	CurlHook::Init();
}
