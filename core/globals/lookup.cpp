#include "globals.h"

cTkFlatMap<unsigned __int64, cTkMetaDataFunctionLookup> *Globals::mgpFunctionLookup;
cTkVector<cTkMetaDataXMLFunctionLookup> *Globals::mgpXMLWriteLookup;

void Globals::SetMetadataLookupDefaults()
{
    Globals::mgpFunctionLookup = (cTkFlatMap<unsigned __int64, cTkMetaDataFunctionLookup> *)OFFSET(0x53AA7C8);
    Globals::mgpXMLWriteLookup = (cTkFlatMap<unsigned __int64, cTkMetaDataFunctionLookup> *)OFFSET(0x53AAA48);
}