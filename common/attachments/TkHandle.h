#pragma once

struct TkHandle
{
	union
	{
		union
		{
			unsigned __int32 miLookup : 18;
			unsigned __int32 miIncrementor : 14;
		};
		unsigned int miLookupInt;
	};
};