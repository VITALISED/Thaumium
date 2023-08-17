#pragma once

#include <memory>

std::_Container_Base =

    template <typename T>
    struct TkSTLAllocatorShim : std::allocator<T>
{
    // TODO: force container to use _Container_base0

    using value_type = T;
    using size_type = std::size_t;
    using pointer = T *;
    using const_pointer = const T *;

    template <typename U>
    struct rebind
    {
        using other = TkSTLAllocatorShim<U>;
    };
};