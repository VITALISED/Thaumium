#pragma once

#include "hooks.h"
#include "memory.h"

namespace FrontendOptions
{
	void Init();
	void PatchOptionsPrepareSwitchStatement();
	void PatchOptionsHeaderSwitchStatement();
	void PatchSwitchMenuJZ();

}