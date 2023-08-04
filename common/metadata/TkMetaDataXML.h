#pragma once

#include "TkClassPointer.h"

class cTkMetaDataXML
{
public:
	template <typename T>
	class Registrar
	{
		void ReadFromXMLNode(XMLNode*) = delete;
		T* Cast(cTkClassPointer* lClassPtr) = delete;
	};

	//typedef bool(*WriteToXMLFile)(T* thiscall, const char* lpacDataType, const char* lpacFileName, bool lbIsGlobal, bool lbWriteBinary, bool lbClearAllExistingData, bool lbWriteText);
};