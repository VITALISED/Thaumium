#pragma once

#include "../util/memory.h"
#include "../nms/GameComponents/GcApplication.h"

#include "textchathandler.h"
#include "frontendoptions.h"
#include "nguimbinexport.h"

#define GCAPPLICATION (cGcApplication*)OFFSET(0x463F810)

namespace Core
{
	void Init();
}