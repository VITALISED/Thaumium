#pragma once

#include "GcUIOptionListElement.h"
#include "TkFixedString.h"

#pragma pack(16)
template<typename T>
class cGcOption : public cGcUIOptionListElement
{
public:
	cGcOption() : cGcUIOptionListElement()
	{ 
		mTranslatedDescription = cTkFixedString<1024, char>();
	};
	T mOptionsMenuValue;
	T* mpValue;
	T mDefaultValue;
	bool mbAutoApply;
	const char* mpacOptionName;
	const char* mpacDescriptionLocKey;
	cTkFixedString<1024, char> mTranslatedDescription;
	void(__fastcall* mpOnUserChanged)();
	bool(__fastcall* mpVisibilityCondition)();
	bool(__fastcall* mpEnabledCondition)();
};