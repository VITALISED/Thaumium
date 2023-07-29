#pragma once

#include "../pch.h"
#include "../nms/Application/GcApplication.h"
#include "../nms/ToolKit/Metadata/TkClassPointer.h"

#include "textchathandler.h"
#include "frontendoptions.h"
#include "nguimbinexport.h"
#include "curlhook.h"

#define GCAPPLICATION (cGcApplication*)OFFSET(0x463F810)

namespace Core
{
	void Init();
}