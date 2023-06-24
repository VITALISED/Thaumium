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
#pragma comment(lib,"libMinHook.x64.lib")

// some libs used by nms, might be useful
// TODO: is nanovg used? if so, how the fuck; the game uses vulkan??? wires 
#include <robin_hood.h>
#include <rapidjson/rapidjson.h>
#include <Eigen/Eigen>

#endif //PCH_H
