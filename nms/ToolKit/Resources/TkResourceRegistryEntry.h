#pragma once

#include <iostream>
#include <robin_hood.h>
#include "TkResource.h"
#include "TkResourceDescriptor.h"
#include "TkSmartResHandle.h"
#include "../Utilities/Memory/TkSTLAllocatorShim.h"

class cTkResourceRegistryEntry
{
	std::basic_string<char, std::char_traits<char>, TkSTLAllocatorShim<char> > msType;
	void(__fastcall* mpInitializationFunc)();
	void(__fastcall* mpReleaseFunc)();
	cTkResource* (__fastcall* mpFactoryFunc)(const std::basic_string<char, std::char_traits<char>, TkSTLAllocatorShim<char> >*, int, cTkResourceDescriptor*);
	robin_hood::detail::Table<true, 80, int, cTkSmartResHandle, robin_hood::hash<int, void>, std::equal_to<int> > mFlagsDefResHandleMap;
};