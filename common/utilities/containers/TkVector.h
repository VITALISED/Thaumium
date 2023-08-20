#pragma once

#include "../../../pch.h"
#include "../allocators/TkSTLAllocator.h"

template <class _Ty, class _Alloc = TkSTLAllocatorShim<_Ty>>
class cTkVector : public std::vector<_Ty>
{
private:
    template <class>
    friend class _Vb_val;
    friend std::_Tidy_guard<cTkVector>;

    using _Alty = std::_Rebind_alloc_t<_Alloc, _Ty>;
    using _Alty_traits = std::allocator_traits<_Alty>;

public:
    using value_type = _Ty;
    using allocator_type = _Alloc;
    using pointer = typename _Alty_traits::pointer;
    using const_pointer = typename _Alty_traits::const_pointer;
    using reference = _Ty &;
    using const_reference = const _Ty &;
    using size_type = typename _Alty_traits::size_type;
    using difference_type = typename _Alty_traits::difference_type;
};