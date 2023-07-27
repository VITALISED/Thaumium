#include "GcBooleanOption.h"
#include "../../pch.h"
#include "../../util/memory.h"

cGcBooleanOption::cGcBooleanOption(const char* lpacName, bool* lpbValue, const char* lpacDescriptionLocKey, bool lbDefault, const char* lpacEnabledString, const char* lpacDisabledString)
{
	this->mbEnabled = true;
	if (lpbValue)
		this->mOptionsMenuValue = *lpbValue;
	else
		this->mOptionsMenuValue = lbDefault;
	this->mDefaultValue = lbDefault;
	this->mpOnUserChanged = 0;
	this->mpVisibilityCondition = 0;
	this->mpEnabledCondition = 0;
	this->mpacDescriptionLocKey = lpacDescriptionLocKey;
	this->mTranslatedDescription = cTkFixedString<1024, char>();
	this->mpacEnabledString = "UI_ENABLED";
	this->mpacDisabledString = "UI_DISABLED";
	this->mpValue = lpbValue;
	this->mbAutoApply = 0;
	if (lpacEnabledString)
		this->mpacEnabledString = lpacEnabledString;
	this->mpacOptionName = lpacName;
	if (lpacDisabledString)
		this->mpacDisabledString = lpacDisabledString;
	this->mpacDisabledString = mpacDisabledString;
	//v12 = this->mpacDescriptionLocKey;
	auto v13 = (char*)"wires!";
	auto v14 = v13;
	int v15;
	long v16;
	int v17;
	long v18;

	spdlog::info("hi");
	if (v13)
	{
		v15 = (uintptr_t)(this + 72) - (uintptr_t)v13;
		v16 = -1;
		do
		{
			++v16;
			spdlog::info("hi!");
		} while (v13[v16]);
		v17 = v16 - 13;
		v18 = v17;
		if (v17 > 0)
		{
			do
			{
				*v13 = v13[14];
				++v13;
				--v18;
				spdlog::info("hi!!");
			} while (v18);
		}
		//cTkStringUtilities<char>::InsertPrefix(v14, v15 + 1024, acPrefix);
	}
}

void cGcBooleanOption::UpdateUI()
{
	__int64 (*mpVisibilityCondition)(void); // rax
	char v3; // al
	__int64 (*mpEnabledCondition)(void); // rax
	char v5; // al
	const char* mpacEnabledString; // rdx
	bool mOptionsMenuValue; // al
	void(__fastcall * *p_mpOnUserChanged)(); // rdi
	bool v9; // si
	bool v10; // zf

	mpVisibilityCondition = (__int64 (*)(void))this->mpVisibilityCondition;
	if (mpVisibilityCondition)
	{
		v3 = mpVisibilityCondition();
		this->mpElement->mpElementData->mbIsHidden = v3 == 0;
		this->mbVisible = v3;
	}
	mpEnabledCondition = (__int64 (*)(void))this->mpEnabledCondition;
	if (mpEnabledCondition)
	{
		v5 = mpEnabledCondition();
		this->SetEnabled(v5);
	}
	if (this->mOptionsMenuValue)
		mpacEnabledString = this->mpacEnabledString;
	else
		mpacEnabledString = this->mpacDisabledString;
	if (!this->mpText)
	{
		spdlog::info("mptext is undefined");
	}
	//this->mpText->SetText("hello!");
	if (this->mbEnabled && this->mpContext->Confirm(this->mpElement, false))
	{
		mOptionsMenuValue = this->mOptionsMenuValue;
		p_mpOnUserChanged = &this->mpOnUserChanged;
		v9 = mOptionsMenuValue != !mOptionsMenuValue && *p_mpOnUserChanged;
		v10 = !this->mbAutoApply;
		this->mOptionsMenuValue = !mOptionsMenuValue;
		if (!v10)
			this->Apply();
		if (v9)
			(*p_mpOnUserChanged)();
	}
}

constexpr int T = sizeof(cGcNGuiLayer);

void cGcBooleanOption::CreateElement()
{
	TkID<128> lID;
	this->mpElement = (cGcNGuiLayer*)malloc(0x160);
	*this->mpElement = cGcNGuiLayer();
	this->mpElement->LoadFromMetadata("UI\\Components\\Options\\OPTIONBUTTON.MXML", 0);

	TKIDSTR(lID, "TEXT");
	lID.mChars[5] = 0;
	lID.mChars[13] = 0;
	this->mpText = this->mpElement->FindTextRecursive(&lID);
	
	TkID<128> lID2;
	TKIDSTR(lID2, "BUTTONMAIN");
	lID2.mChars[11] = 0;
	this->mpButton = this->mpElement->FindLayerRecursive(&lID2);
}

void cGcBooleanOption::GetTranslatedDefaultValue()
{
	std::cout << "is this used?";
}