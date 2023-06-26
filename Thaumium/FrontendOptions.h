#pragma once

#include "hooks.h"
#include "memory.h"
#include "shadowtable.h"
#include "NMS/GcNGuiText.h"

namespace FrontendOptions
{
	void Init();
	void PatchOptionsPrepareSwitchStatement();
	void PatchOptionsHeaderSwitchStatement();
	void PatchSwitchMenuJZ();

}