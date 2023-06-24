#pragma once
#include "pch.h"

constexpr uint32_t hash(const char* data, size_t const size) noexcept {
    uint32_t hash = 5381;

    for (const char* c = data; c < data + size; ++c)
        hash = ((hash << 5) + hash) + (unsigned char)*c;

    return hash;
}