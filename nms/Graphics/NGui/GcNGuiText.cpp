#include "GcNGuiText.h"

void cGcNGuiText::SetText(const char* lpacText)
{
	this->mpTextData->macText = cTkFixedString<512, char>("wires");
}

void cGcNGuiText::Render()
{
	typedef void (*fptr)(cGcNGuiText*);
	fptr func = (fptr)OFFSET(0x8760D0);
	func(this);
}

void cGcNGuiText::EditElement()
{
	typedef void (*fptr)(cGcNGuiText*);
	fptr func = (fptr)OFFSET(0x868880);
	func(this);
}

void cGcNGuiText::AttachMetadata(cTkClassPointer* lClass)
{
	this->mpTextData->WriteToClassPtr(lClass);
}

eNGuiEditorIcons cGcNGuiText::GetSceneTreeIcon()
{
	return EIcon_font;
}

void cGcNGuiText::GetSceneTreeText(cTkFixedString<128, char>* lOutResult)
{
	//FIXME: too lazy to add more string helpers right now
	typedef void (*fptr)(cGcNGuiText*, cTkFixedString<128, char>*);
	fptr func = (fptr)OFFSET(0x86EF70);
	func(this, lOutResult);
}

void cGcNGuiText::Convert()
{
	typedef void (*fptr)(cGcNGuiText*);
	fptr func = (fptr)OFFSET(0x867680);
	func(this);
}