#pragma once

class cTkMetaDataClass;

const struct FloatEditOptions
{
    float mfStepSize;
    int miDecimalPrecision;
    bool mbUnspecified;
};

const struct FloatLimits
{
    float mfMin;
    float mfMax;
    bool mbUnspecified;
};

const class cTkMetaDataEnumLookup
{
public:
    __int64 miValue;
    const char *mpacName;
};

const class cTkMetaDataMember
{
public:
    enum eType : __int32
    {
        EType_Unspecified = 0x0,
        EType_Bool = 0x1,
        EType_Byte = 0x2,
        EType_Class = 0x3,
        EType_ClassPointer = 0x4,
        EType_Colour = 0x5,
        EType_DynamicArray = 0x6,
        EType_DynamicString = 0x7,
        EType_DynamicWideString = 0x8,
        EType_Enum = 0x9,
        EType_Filename = 0xA,
        EType_Flags = 0xB,
        EType_Float = 0xC,
        EType_Id = 0xD,
        EType_Id256 = 0xE,
        EType_LocId = 0xF,
        EType_Int8 = 0x10,
        EType_Int16 = 0x11,
        EType_Int = 0x12,
        EType_Int64 = 0x13,
        EType_NodeHandle = 0x14,
        EType_Resource = 0x15,
        EType_Seed = 0x16,
        EType_StaticArray = 0x17,
        EType_String32 = 0x18,
        EType_String64 = 0x19,
        EType_String128 = 0x1A,
        EType_String256 = 0x1B,
        EType_String512 = 0x1C,
        EType_String1024 = 0x1D,
        EType_String2048 = 0x1E,
        EType_UInt8 = 0x1F,
        EType_UInt16 = 0x20,
        EType_UInt = 0x21,
        EType_UInt64 = 0x22,
        EType_UniqueId = 0x23,
        EType_Vector2 = 0x24,
        EType_Vector = 0x25,
        EType_Vector4 = 0x26,
        EType_WideChar = 0x27,
        EType_HalfVector4 = 0x28,
        EType_PhysRelVec = 0x29,
    };

    const char *mpacName;
    const unsigned int miNameHash;
    const char *mpacCategoryName;
    const unsigned int miCategoryHash;
    const cTkMetaDataMember::eType mType;
    const cTkMetaDataMember::eType mInnerType;
    const int miSize;
    const int miCount;
    const int miOffset;
    const cTkMetaDataClass *mpClassMetadata;
    const cTkMetaDataEnumLookup *mpEnumLookup;
    const int miNumEnumMembers;
    const FloatEditOptions mFloatEditOptions;
    const FloatLimits mFloatLimits;
};

const class cTkMetaDataClass
{
public:
    const char *mpacName;
    const unsigned __int64 muNameHash;
    const unsigned __int64 muTemplateHash;
    const cTkMetaDataMember *maMembers;
    const int miNumMembers;
};