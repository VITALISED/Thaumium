#pragma once

template <unsigned int size, unsigned int alignment>
struct cTkAlignedBlock
{
	unsigned __int8 data_[size * alignment];
};