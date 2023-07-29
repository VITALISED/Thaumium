#pragma once

#include "../pch.h"

#include "../nms/Graphics/NGui/GcNGuiText.h"
#include "../nms/Graphics/NGui/Options/GcFrontendPageOptions.h"
#include "../nms/Graphics/NGui/Options/GcOptionsMenuState.h"
#include "../nms/Graphics/NGui/Options/GcUIOptionListElement.h"
#include "../nms/Graphics/NGui/Options/GcBooleanOption.h"
#include "../nms/ToolKit/Utilities/Memory/TkSTLAllocatorShim.h"

namespace FrontendOptions
{
	void Init();
	cGcUIOptionListElement** HookPrepareBootScreenOptions();
	void PatchOptionsHeaderSwitchStatement();
	void PatchSwitchMenuJZ();
}