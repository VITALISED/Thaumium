#include "GcNGuiTextData.h"

void cGcNGuiTextData::WriteToClassPtr(cTkClassPointer* lClassPtr)
{
	lClassPtr->mClassName = cTkFixedString<63, char>("cGcNGuiTextData");
	lClassPtr->mClassData.miOffset = (uintptr_t)this;
	lClassPtr->mClassNameHash = 0x4C5F02B93CB08B1A;
	lClassPtr->mbClassFixed = true;
}