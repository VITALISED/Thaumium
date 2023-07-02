#pragma once

#include <memory>

template<typename T>
struct TkSTLAllocatorShim : std::allocator<T>
{ };