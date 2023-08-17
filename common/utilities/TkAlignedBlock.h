#pragma once

template <unsigned int size, unsigned int alignment>
struct cTkAlignedBlock
{
	unsigned __int8 data_[(alignment == 1) ? size * (align + 3) : size * alignment];
};