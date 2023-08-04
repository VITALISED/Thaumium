#pragma once

namespace TkStrongTypeIDs
{
	struct TkResHandleID
	{ };
}

// No idea how this is meant to work, probably just inline assert crap
template <typename T, class StrongType>
class TkStrongType
{
public:
	T mValue;
};