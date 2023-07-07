#include "GcNGuiText.h"

void cGcNGuiText::SetText(const char* lpacText)
{
	this->mpTextData->macText = cTkFixedString<512, char>(lpacText);
}