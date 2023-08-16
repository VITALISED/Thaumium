#pragma once

template <typename T>
class cTkStackVector : public StackContainer<std::vector<T, StackAllocator<T>>>
{
};