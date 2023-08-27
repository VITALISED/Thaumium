#pragma once

#include "../../../pch.h"
#include "../allocators/TkSTLAllocator.h"

template <class _Ty, class _Alloc = TkSTLAllocatorShim<_Ty>>
class cTkVector : public std::vector<_Ty>
{
public:
    using value_type = _Ty;
    using allocator_type = _Alloc;
};