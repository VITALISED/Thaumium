#pragma once
#include "GcNGuiText.h"
#include "GcNGuiLayer.h"
#include "GcOption.h"

class cGcBooleanOption : public cGcOption<bool>
{
public:
	cGcBooleanOption() : cGcOption<bool>()
	{ }

	typedef cGcBooleanOption(__fastcall* _cGcBooleanOption)(cGcBooleanOption* _this, const char* lpacName, bool* lpbValue, const char *lpacDescriptionLocKey, bool lbDefault, const char *lpacEnabledString, const char* lpacDisabledString);

	const char* mpacEnabledString;
	const char* mpacDisabledString;
	cGcNGuiText* mpText;
	cGcNGuiLayer* mpButton;
};