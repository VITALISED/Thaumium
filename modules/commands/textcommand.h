#pragma once

#include <iostream>

class ITextCommand
{
	virtual std::string GetName() = 0;
	virtual std::string GetDescription() = 0;
	virtual void Execute() = 0;
};