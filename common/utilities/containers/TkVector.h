#pragma once

#include "../../../pch.h"
#include "../allocators/TkSTLAllocator.h"

template <typename T>
class cTkVector : std::vector<T, TkSTLAllocatorShim<T>>
{
}