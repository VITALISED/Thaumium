#pragma once

namespace WinHttpTask
{
	struct State
	{
		enum Enum : __int32
		{
			Invalid = 0x0,
			Working = 0x1,
			Complete = 0x2,
			Failed = 0x3,
			__EnumTerminator = 0x4,
			Unspecified = 0x5,
		};
	};
}