#pragma once
#include "NMS/GcApplication.h"

#define GCAPPLICATION() (cGcApplication*)OFFSET(0x463F810)

namespace Core
{
	void Init();
}