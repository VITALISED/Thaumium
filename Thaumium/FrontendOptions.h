#pragma once

#include "hooks.h"

namespace FrontendOptions
{
	void Init();
	void PatchOptionsPrepareSwitchStatement();
	void PatchOptionsHeaderSwitchStatement();
	void PatchOptionsMenuStateVectorItems();
}