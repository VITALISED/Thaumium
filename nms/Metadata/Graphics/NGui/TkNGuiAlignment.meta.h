#pragma once

#include <iostream>

#include "../NGui/Vertical.h"
#include "../NGui/Horizontal.h"

class cTkNGuiAlignment
{
public:
	eVertical meVertical;
	eHorizontal meHorizontal;

	void SetDefaults();
};