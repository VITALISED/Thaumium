#pragma once

template <typename T>
struct StackContainer
{
	typename T::allocator_type::Source stack_data_;
	typename T::allocator_type allocator_;
	T container_;
};
