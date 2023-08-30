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

    template <class T>
    class Registrar
    {
    public:
        static void ClassPointerRead(cTkClassPointer *lPtr, XMLNode *lDataNode, cTkLinearMemoryPool *lpAllocator);
        static bool ClassPointerSave(const cTkClassPointer *lPtr, const char *lpacFilename);
        static void ClassPointerWrite(const cTkClassPointer *lPtr, XMLNode *lDataNode, bool lbForceShortForm);
        void WriteToXMLNode(XMLNode *lDataNode, bool lbForceShortForm, bool lbGlobal);
    };
};