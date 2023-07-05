#pragma once

enum eAnimate : __int8
{
	EAnimate_None = 0x0,
	EAnimate_WipeRightToLeft = 0x1,
	EAnimate_SimpleWipe = 0x2,
	EAnimate_SimpleWipeDown = 0x3,
	EAnimate_CustomWipe = 0x4,
	EAnimate_CustomWipeAlpha = 0x5,
	EAnimate_NumTypes = 0x6,
};