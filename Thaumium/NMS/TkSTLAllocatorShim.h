#pragma once

#include <memory>

template<typename T>
struct TkSTLAllocatorShim
{
	template <T*>
	struct rebind;

	template <std::_Container_proxy>
	struct rebind;
};