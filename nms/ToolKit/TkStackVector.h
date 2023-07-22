#pragma once

#include "TkAlignedBlock.h"

#include <vector>
#include <memory>

template <typename T>
struct __declspec(align(8)) StackAllocator : std::allocator<T>
{
	using value_type = T;

	template<typename U>
	struct rebind {
		using other = StackAllocator<U>;
	};

	struct Source
	{
		cTkAlignedBlock<sizeof(T), alignof(T)> stack_buffer_;
		bool used_stack_buffer_;
	};
};

template <typename T>
struct StackContainer
{
	typename T::allocator_type::Source stack_data_;
	typename T::allocator_type allocator_;
	T container_;
};

template <typename T>
class cTkStackVector : public StackContainer<std::vector<T, StackAllocator<T> > >
{ };