#include "globals.h"

// cTkFlatMap<unsigned __int64, cTkMetaDataFunctionLookup> *Globals::mgpFunctionLookup;
// cTkVector<cTkMetaDataXMLFunctionLookup> *Globals::mgpXMLWriteLookup;

void Globals::SetMetadataLookupDefaults()
{
    Globals::mgpFunctionLookup = reinterpret_cast<cTkFlatMap<unsigned __int64, cTkMetaDataFunctionLookup> *>(OFFSET(0x53AA7C8));
    Globals::mgpXMLWriteLookup = reinterpret_cast<cTkVector<cTkMetaDataXMLFunctionLookup> *>(OFFSET(0x53AAA48));
}