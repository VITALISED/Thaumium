#pragma once

#include "../../pch.h"
#include "../TkAlignedBlock.h"
#include <memory>
#include <vector>

template <typename T>
struct ALIGN(8) StackAllocator : std::allocator<T>
{
	using value_type = T;

	template <typename U>
	struct rebind
	{
		using other = StackAllocator<U>;
	};

	struct Source
	{
		cTkAlignedBlock<sizeof(T), alignof(T)> stack_buffer_;
		bool used_stack_buffer_;
	};
};