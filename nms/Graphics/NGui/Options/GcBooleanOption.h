#pragma once
#include <iostream>

#include "../pch.h"
#include "../GcNGuiText.h"
#include "GcOption.h"

class cGcBooleanOption : public cGcOption<bool>
{
private:
public:
	cGcBooleanOption(const char* lpacName, bool* lpbValue, const char* lpacDescriptionLocKey, bool lbDefault, const char* lpacEnabledString, const char* lpacDisabledString);

	const char* mpacEnabledString;
	const char* mpacDisabledString;
	cGcNGuiText* mpText;
	cGcNGuiLayer* mpButton;

	void GetTranslatedDefaultValue();
	void UpdateUI();
	void CreateElement();

	~cGcBooleanOption()
	{
		delete this;
	}
};