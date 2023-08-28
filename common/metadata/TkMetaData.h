#pragma once

#include "../utilities/pools/TkLinearMemoryPool.h"
#include "TkClassPointer.h"
#include "TkMetaDataClass.h"
#include "TkMetaDataXML.h"

class cTkMetaDataFunctionLookup
{
public:
    const cTkMetaDataClass *mpClassMetadata;
    void (*mCreateDefaultFunction)(cTkClassPointer *, cTkLinearMemoryPool *);
    void (*mRenderFunction)(cTkClassPointer *);
    void (*mFixingFunction)(cTkClassPointer *, bool, unsigned __int64);
    void (*mValidateDataFunction)(cTkClassPointer *);
    bool (*mEqualsFunction)(const cTkClassPointer *, const cTkClassPointer *);
    void (*mCopyFunction)(cTkClassPointer *, const cTkClassPointer *);
    cTkClassPointer *(*mCreatePtrFunction)(cTkClassPointer *result);
    unsigned __int64 (*mHashFunction)(const cTkClassPointer *, unsigned __int64, bool);
    void (*mDestroyFunction)(cTkClassPointer *);
};

class cTkMetaData
{
public:
    typedef cTkMetaDataFunctionLookup *(*GetLookup)(unsigned __int64 luiNameHash);
    typedef __int64 (*Register)(
        const cTkMetaDataClass *lpClassMetadata,
        void (*lDefaultFunction)(cTkClassPointer *, cTkLinearMemoryPool *),
        void (*lFixingFunction)(cTkClassPointer *, bool, unsigned __int64),
        void (*lValidateFunction)(cTkClassPointer *),
        void (*lRenderFunction)(cTkClassPointer *),
        bool (*lEqualsFunction)(const cTkClassPointer *, const cTkClassPointer *),
        void (*lCopyFunction)(cTkClassPointer *, const cTkClassPointer *),
        cTkClassPointer *(*lCreateFunction)(cTkClassPointer *result),
        unsigned __int64 (*lHashFunction)(const cTkClassPointer *, unsigned __int64, bool),
        void (*lDestroyFunction)(cTkClassPointer *));

    template <class T>
    class Registrar : public cTkMetaDataXML::Registrar<T>
    {
    public:
        static T *Cast(cTkClassPointer *lClassPtr);
        static bool ClassPointerCompare(const cTkClassPointer *lPtr, const cTkClassPointer *lOtherPtr);
        static void ClassPointerCopy(cTkClassPointer *lDest, const cTkClassPointer *lSource);
        static cTkClassPointer *ClassPointerCreate(cTkClassPointer *result);
        static void ClassPointerCreateDefault(cTkClassPointer *lPtr, cTkLinearMemoryPool *lpAllocator);
        static void ClassPointerDestroy(cTkClassPointer *lPtr);
        static void ClassPointerFix(cTkClassPointer *lPtr, bool lbFixUp, unsigned __int64 liDynamicOffset);
        unsigned __int64 GenerateHash(unsigned __int64 luHash, bool lbDeep);
    };
};