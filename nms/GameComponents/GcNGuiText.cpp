#include "GcNGuiText.h"

void cGcNGuiText::SetText(const char* lpacText)
{
	this->mpTextData->macText.Copy(lpacText);
}