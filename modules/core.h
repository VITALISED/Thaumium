#pragma once

#include "../util/memory.h"
#include "../nms/GameComponents/GcApplication.h"

#include "TextChatHandler.h"
#include "FrontendOptions.h"

#define GCAPPLICATION (cGcApplication*)OFFSET(0x463F810)

namespace Core
{
	void Init();
}