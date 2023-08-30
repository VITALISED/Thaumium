// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

#include "framework.h"

#include <MinHook.h>
#include <fmt/format.h>
#include <spdlog/spdlog.h>

#include "source/core/hooks.h"
#include "source/core/memory.h"

#include "common/utilities/spookyhash/SpookyV2.h"
#include <iostream>
#include <robin_hood.h>
#include <vector>

#if FRACTAL
#define BRANCH "fractal"
#elif UPSTREAM
#define BRANCH "upstream"
#endif

#define __VERSION(v) #v
#define __VERSION__(v) __VERSION(v)
#define __THAUMIUM_VER(branch, version) (std::string(branch) + "_" + __VERSION__(VERSION))

#define THAUMIUM_VER __THAUMIUM_VER(BRANCH, VERSION)

#endif // PCH_H
