#include "GcNGuiElement.h"

//Note: this will probably never get completely implemented due to how complex the original is.
void cGcNGuiElement::Render()
{
	typedef void (*fptr)(cGcNGuiElement*);
	fptr func = (fptr)OFFSET(0x875B40);
	func(this);
}