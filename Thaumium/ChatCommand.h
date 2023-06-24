#pragma once

struct ChatCommand
{
	enum Category
	{
		Stock, 
		Thaumium, 
		Custom,
	};

	ChatCommand(const char* name, const char* description, const char* longDescription, Category category, uintptr_t callback)
	{
		sName = name;
		sDescription = description;
		sLongDescription = longDescription;
		eCategory = category;
		pCallback = callback;
	};

	const char* sName;
	const char* sDescription;
	const char* sLongDescription;
	Category eCategory;
	uintptr_t pCallback; //typedef this to something useful
};