#include "../pch.h"
#include "GcBooleanOption.h"

cGcBooleanOption::cGcBooleanOption(const char* lpacName, bool* lpbValue, const char* lpacDescriptionLocKey, bool lbDefault, const char* lpacEnabledString, const char* lpacDisabledString)
{
	bool v8; // al
	const char* mpacEnabledString; // rcx
	const char* mpacDisabledString; // rcx
	const char* v12; // rax
	char* v13; // rax
	char* v14; // r9
	int v15; // edi
	__int64 v16; // rcx
	int v17; // ecx
	__int64 v18; // r8
	char acPrefix[40]; // [rsp+20h] [rbp-28h] BYREF

	this->mbEnabled = true;
	if (lpbValue)
		v8 = *lpbValue;
	else
		v8 = lbDefault;
	this->mOptionsMenuValue = v8;
	this->mDefaultValue = lbDefault;
	this->mpOnUserChanged = 0i64;
	this->mpVisibilityCondition = 0i64;
	this->mpEnabledCondition = 0i64;
	this->mpacDescriptionLocKey = lpacDescriptionLocKey;
	this->mTranslatedDescription.macBuffer[0] = 0;
	this->mpacEnabledString = "UI_ENABLED";
	mpacEnabledString = this->mpacEnabledString;
	this->mpacDisabledString = "UI_DISABLED";
	this->mpValue = lpbValue;
	this->mbAutoApply = 0;
	if (lpacEnabledString)
		mpacEnabledString = lpacEnabledString;
	this->mpacOptionName = lpacName;
	this->mpacEnabledString = mpacEnabledString;
	mpacDisabledString = this->mpacDisabledString;
	if (lpacDisabledString)
		mpacDisabledString = lpacDisabledString;
	this->mpacDisabledString = mpacDisabledString;
	v12 = this->mpacDescriptionLocKey;
	v13 = (char*)"wires!";
	v14 = v13;
	spdlog::info("hi");
	if (v13)
	{
		v15 = (DWORD)this + 72 - (DWORD)v13;
		v16 = -1i64;
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
		cGcUIOptionListElement::SetEnabled(v5);
	}
	if (this->mOptionsMenuValue)
		mpacEnabledString = this->mpacEnabledString;
	else
		mpacEnabledString = this->mpacDisabledString;
	this->mpText->SetText(mpacEnabledString);
	if (this->mbEnabled && cGcOptionsInteractionContext::Confirm(this->mpContext, this->mpElement, 0))
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

void cGcBooleanOption::CreateElement()
{

}

void cGcBooleanOption::GetTranslatedDefaultValue()
{
	std::cout << "is this used?";
}