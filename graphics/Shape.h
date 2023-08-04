#pragma once

enum eShape : __int32
{
	EShape_Rectangle = 0x0,
	EShape_Ellipse = 0x1,
	EShape_Line = 0x2,
	EShape_LineInverted = 0x3,
	EShape_Bezier = 0x4,
	EShape_BezierInverted = 0x5,
	EShape_BezierWide = 0x6,
	EShape_BezierWideInverted = 0x7,
	EShape_NumTypes = 0x8,
};
