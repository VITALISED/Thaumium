#pragma once
#include "textcommand.h"

class DebugWalkerTitanfall : ITextCommand
{
	std::string name;
	std::string description;

	void Execute();

	std::string GetName()
	{
		return this->name;
	}

	std::string GetDescription()
	{
		return this->description;
	}
};