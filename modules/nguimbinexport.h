#pragma once
#include "../nms/GameComponents/GcNGuiLayerData.h"
#include "../nms/ToolKit/TkMetaDataXML.h"

namespace NGuiMBINExport
{
	void Init();
	bool SaveHook(cGcNGuiLayerData* thiscall, const char* lpacFileName, bool lbClearAllExistingData);
}