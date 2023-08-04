#pragma once

#include <memory>

template<typename T>
struct TkSTLAllocatorShim : std::allocator<T>
{ 
    using value_type = T;

    template<typename U>
    struct rebind {
        using other = TkSTLAllocatorShim<U>;
    };
};