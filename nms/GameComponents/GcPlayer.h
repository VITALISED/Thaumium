#pragma once

class cGcPlayer
{
public:
	enum eRocketBootsDoubleTapState : __int32
	{
		None = 0x0,
		WaitingForRelease = 0x1,
		WaitingForSecondTap = 0x2,
		SingleTap = 0x3,
		DoubleTap = 0x4,
	};
};