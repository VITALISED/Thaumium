#include "GcNGuiElement.h"

void cGcNGuiElement::Render()
{
	typedef void (*fptr)(cGcNGuiElement*);
	fptr func = (fptr)OFFSET(0x875B40);
	func(this);
}

void cGcNGuiElement::EditElement()
{
	typedef void (*fptr)(cGcNGuiElement*);
	fptr func = (fptr)OFFSET(0x868710);
	func(this);
}

void cGcNGuiElement::EditPresets(cGcNGuiPreset* lpGuiPreset)
{
	typedef void (*fptr)(cGcNGuiElement*, cGcNGuiPreset*);
	fptr func = (fptr)OFFSET(0x8519D0);
	func(this, lpGuiPreset);
}

void cGcNGuiElement::RenderUIEditorToolbar(cGcNGuiPreset* lpGuiPreset)
{
	typedef void (*fptr)(cGcNGuiElement*, cGcNGuiPreset*);
	fptr func = (fptr)OFFSET(0x851FF0);
	func(this, lpGuiPreset);
}

void cGcNGuiElement::Deselect()
{
	this->mbSelectedToEdit = false;
}

bool cGcNGuiElement::IsSelected()
{
	return this->mbSelectedToEdit;
}

void cGcNGuiElement::Resized()
{
	this->meLayoutChangeEvent = ELayoutChange_Size;
}

void cGcNGuiElement::RenderTreeControls()
{
	typedef void (*fptr)(cGcNGuiElement*);
	fptr func = (fptr)OFFSET(0x852F70);
	func(this);
}