// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

#include "framework.h"

#include <spdlog/spdlog.h>
#include <fmt/format.h>
#include <MinHook.h>

#include "util/memory.h"
#include "util/hooks.h"

// some libs used by nms
// TODO: is nanovg used? if so, how the fuck; the game uses vulkan, is it legacy?
#include <robin_hood.h>

#endif //PCH_H
