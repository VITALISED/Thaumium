#pragma once

#include "../utilities/TkString.h"
#include "../utilities/pools/TkLinearMemoryPool.h"
#include "../xml/XMLNode.h"
#include "TkClassPointer.h"

class cTkMetaDataXMLFunctionLookup
{
public:
    cTkFixedString<64, char> mName;
    void (*mWriteFunction)(const cTkClassPointer *, XMLNode *, bool);
    void (*mReadFunction)(cTkClassPointer *, XMLNode *, cTkLinearMemoryPool *);
    bool (*mSaveFunction)(const cTkClassPointer *, const char *);
};

class cTkMetaDataXML
{
public:
    typedef cTkMetaDataXMLFunctionLookup *(*GetLookup)(const char *lpacName);
};