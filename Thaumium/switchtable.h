#pragma once

#include <iostream>
#include <cstring>

// SHADOW WIZARD MONEY GANG         //
//          we love casting spells  //
class ShadowJMPT {
public:
    uintptr_t ObjectPtr;
    uintptr_t OriginalTable;
    uintptr_t ShadowTable;
    unsigned int MethodCount;
    unsigned int OriginalCount;

    ShadowJMPT()
    { };
    ShadowJMPT(uintptr_t objectPtr, unsigned int methodCount)
    {
        this->ObjectPtr = objectPtr;
        this->ShadowTable = reinterpret_cast<uintptr_t>(std::malloc(methodCount * 8));
        this->OriginalTable = *reinterpret_cast<uintptr_t*>(objectPtr);
        this->MethodCount, this->OriginalCount = methodCount;
        std::memcpy(reinterpret_cast<void*>(this->ShadowTable), *reinterpret_cast<void**>(objectPtr), methodCount * 8);
    };

    void Hook(unsigned int idx, uintptr_t* original, uintptr_t hook)
    {
        *original = *reinterpret_cast<uintptr_t*>(this->OriginalTable + (idx * 8));
        *reinterpret_cast<uintptr_t*>(this->ShadowTable + (idx * 8)) = hook;
    };

    void Append(uintptr_t item)
    {
        MethodCount++;
        this->ShadowTable = reinterpret_cast<uintptr_t>(std::realloc((void*)this->ShadowTable, MethodCount * 8));
        *reinterpret_cast<uintptr_t*>(this->ShadowTable + (MethodCount * 8)) = item;
    }

    void Apply()
    {
        *reinterpret_cast<uintptr_t*>(this->ObjectPtr) = reinterpret_cast<uintptr_t>(this->ShadowTable);
    };
};