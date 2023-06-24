#pragma once
#include "NMS/GcApplication.h"
#include "TextChatHandler.h"

#define GCAPPLICATION (cGcApplication*)OFFSET(0x463F810)

namespace Core
{
	void Init();
}