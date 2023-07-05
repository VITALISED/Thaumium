#pragma once

enum eNGuiInputType
{
	eInput_RightDragged = 0xF8,
	eInput_RightPressed = 0xF9,
	eInput_RightHeld = 0xFA,
	eInput_Hover = 0xFB,
	eInput_Dragged = 0xFC,
	eInput_TouchPressReady = 0xFD,
	eInput_Pressed = 0xFE,
	eInput_Held = 0xFF,
	eInput_None = 0x0,
	eInput_Released = 0x1,
	eInput_Click = 0x2,
	eInput_RightReleased = 0x3,
	eInput_RightClick = 0x4,
};