#pragma once

#include "../util/hooks.h"
#include "../util/memory.h"
#include "../nms/GameComponents/GcNGuiText.h"
#include "../nms/GameComponents/GcFrontendPageOptions.h"
#include "../nms/GameComponents/GcOptionsMenuState.h"
#include "../nms/GameComponents/GcUIOptionListElement.h"
#include "../nms/GameComponents/GcBooleanOption.h"
#include "../nms/ToolKit/TkSTLAllocatorShim.h"

namespace FrontendOptions
{
	void Init();
	cGcUIOptionListElement** HookPrepareBootScreenOptions();
	void PatchOptionsHeaderSwitchStatement();
	void PatchSwitchMenuJZ();
}