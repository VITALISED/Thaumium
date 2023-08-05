#pragma once

#include <array>

template<int states>
class TkIterationState
{
	std::array<unsigned __int64, states> muIndices;
	std::array<bool, states> mbInnerStates;
};
