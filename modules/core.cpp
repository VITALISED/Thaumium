#include "core.h"
#include "../nms/ToolKit/Metadata/TkClassPointer.h"

std::vector<cTkClassPointer> gvDefinedMetadata;

void Core::Init()
{
	gvDefinedMetadata = std::vector<cTkClassPointer>();

	TextChatHandler::Init();
	NGuiMBINExport::Init();
	//FIXME: 
	//FrontendOptions::Init(); 
	CurlHook::Init();
}
