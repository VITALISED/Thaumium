#pragma once

#include <iostream>

#include "../NGui/eVertical.h"
#include "../NGui/eHorizontal.h"

class cTkNGuiAlignment
{
public:
	eVertical meVertical;
	eHorizontal meHorizontal;

	void SetDefaults();
};