#pragma once

#include <memory>

template<typename T>
struct TkSTLAllocatorShim : std::allocator<T>
{ };

static_assert(sizeof(TkSTLAllocatorShim<bool>) == 1, "guihahs");