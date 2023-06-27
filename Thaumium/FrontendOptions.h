#pragma once

#include "hooks.h"
#include "memory.h"
#include "NMS/GcNGuiText.h"
#include "NMS/GcFrontendPageOptions.h"

namespace FrontendOptions
{
	void Init();
	cGcUIOptionListElement** HookPrepareBootScreenOptions();
	void PatchOptionsHeaderSwitchStatement();
	void PatchSwitchMenuJZ();
}