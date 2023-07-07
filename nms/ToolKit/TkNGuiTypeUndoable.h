#pragma once
#include "TkNGuiUndoable.h"

template <typename T>
class cTkNGuiTypeUndoable : public cTkNGuiUndoable
{
	T mFrom;
	T mTo;
	T* mpValue;
};
