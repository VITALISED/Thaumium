#pragma once
#include <iostream>

#include "GcOption.h"
#include "GcNGuiText.h"

class cGcBooleanOption : public cGcOption<bool>
{
private:
	typedef void(__fastcall* __CreateElement)(cGcBooleanOption* thiscall);
	typedef void(__fastcall* __cGcBooleanOption)(cGcBooleanOption* thiscall, const char* lpacName, bool* lpbValue, const char* lpacDescriptionLocKey, bool lbDefault, const char* lpacEnabledString, const char* lpacDisabledString);

public:
	cGcBooleanOption(const char* lpacName, bool* lpbValue, const char* lpacDescriptionLocKey, bool lbDefault, const char* lpacEnabledString, const char* lpacDisabledString);

	const char* mpacEnabledString;
	const char* mpacDisabledString;
	cGcNGuiText* mpText;
	cGcNGuiLayer* mpButton;

	void GetTranslatedDefaultValue()
	{
		std::cout << "is this used?";
	}

	void UpdateUI();
	void CreateElement()
	{
		cGcBooleanOption::__CreateElement offset = (cGcBooleanOption::__CreateElement)OFFSET(0x562AE0);
		offset(this);
	}

	~cGcBooleanOption()
	{
		delete this;
	}
};
