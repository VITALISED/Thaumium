#pragma once

#include <Havok/hkAabb.h>

#include "TkClassPointer.h"
#include "../xml/XMLNode.h"

class cTkMetaDataXML
{
public:
	template <class T>
	class Registrar
	{
		void ReadFromXMLNode(XMLNode* lDataNode, bool lbMergeWithExisting) = delete;
		void WriteToXMLNode(XMLNode* lDataNode, bool lbForceShortForm, bool lbGlobal)
		{
			T* lpDefaultObject = new T();
			if (lpDefaultObject)
			{
				this->WriteToXMLNodeExplicit(lDataNode, lbForceShortForm, lbGlobal, lpDefaultObject);
				delete T;
			}
			else
			{
				this->WriteToXMLNodeExplicit(lDataNode, lbForceShortForm, lbGlobal, NULL);
			}
		};
		void WriteToXMLNodeExplicit(XMLNode* lDataNode, bool lbForceShortForm, bool lbGlobal, const T* lpDefaultObject) = delete;
		T* Cast(cTkClassPointer* lClassPtr) = delete;
		T* Cast(const cTkClassPointer* lClassPtr) = delete;
		bool ClassPointerCompare(const cTkClassPointer* lPtr, const cTkClassPointer* lOtherPtr)
		{
			return this->Cast(lPtr) == this->Cast(lOtherPtr);
		}
		unsigned __int64 GenerateHash(unsigned __int64 luHash, bool lbDeep) = delete;
		void FixDown(hkAabb* liDynamicOffset) = delete;
		void FixUp(hkAabb* liDynamicOffset) = delete;
	};

	//typedef bool(*WriteToXMLFile)(T* thiscall, const char* lpacDataType, const char* lpacFileName, bool lbIsGlobal, bool lbWriteBinary, bool lbClearAllExistingData, bool lbWriteText);
};