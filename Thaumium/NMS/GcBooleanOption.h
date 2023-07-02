#pragma once
#include <iostream>

#include "GcOption.h"
#include "GcNGuiText.h"

class cGcBooleanOption : cGcOption<bool>
{
	const char* mpacEnabledString;
	const char* mpacDisabledString;
	cGcNGuiText* mpText;
	cGcNGuiLayer* mpButton;

	virtual void GetTranslatedDefaultValue()
	{
		std::cout << "wires";
	}
};
