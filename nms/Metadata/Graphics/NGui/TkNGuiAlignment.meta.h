#pragma once

#include <iostream>

#include "../nms/Graphics/Vertical.h"
#include "../nms/Graphics/Horizontal.h"

class cTkNGuiAlignment
{
public:
	eVertical meVertical;
	eHorizontal meHorizontal;

	void SetDefaults();
};