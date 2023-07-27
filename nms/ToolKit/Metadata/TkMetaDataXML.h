#pragma once

//FIXME: template is called at class member level pretty sure
template <typename T>
class cTkMetaDataXML
{
public:
	typedef bool(*WriteToXMLFile)(T* thiscall, const char* lpacDataType, const char* lpacFileName, bool lbIsGlobal, bool lbWriteBinary, bool lbClearAllExistingData, bool lbWriteText);
};