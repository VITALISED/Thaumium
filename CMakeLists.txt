cmake_minimum_required(VERSION 3.15)

project(
    Thaumium
    LANGUAGES CXX ASM_MASM
    VERSION 0.0.1
)

# Language specs
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(USEFRACTAL "Compile for Fractal 4.13 Debug" OFF)

file(GLOB_RECURSE METADATA_SOURCE ${CMAKE_SOURCE_DIR}/metadata/source/*)
file(GLOB_RECURSE METADATA_TOOLKIT ${CMAKE_SOURCE_DIR}/metadata/toolkit/*)

set(TOOLKIT_SOURCES
    ${CMAKE_SOURCE_DIR}/common/attachments/TkHandle.h
    ${CMAKE_SOURCE_DIR}/common/graphics/TkColour.h/
    ${CMAKE_SOURCE_DIR}/common/maths/TkAABB.h
    ${CMAKE_SOURCE_DIR}/common/maths/TkBBox2d.h
    ${CMAKE_SOURCE_DIR}/common/maths/TkMatrix34.h
    ${CMAKE_SOURCE_DIR}/common/maths/TkPhysRelVec3.h
    ${CMAKE_SOURCE_DIR}/common/maths/TkVector2.h
    ${CMAKE_SOURCE_DIR}/common/maths/TkVector3.h
    ${CMAKE_SOURCE_DIR}/common/maths/TkVector4.h
    ${CMAKE_SOURCE_DIR}/common/metadata/TkClassPointer.h
    ${CMAKE_SOURCE_DIR}/common/metadata/TkID.h
    ${CMAKE_SOURCE_DIR}/common/metadata/TkMetaData.h
    ${CMAKE_SOURCE_DIR}/common/metadata/TkMetaDataClass.h
    ${CMAKE_SOURCE_DIR}/common/metadata/TkMetaDataXML.h
    ${CMAKE_SOURCE_DIR}/common/resources/TkResource.h
    ${CMAKE_SOURCE_DIR}/common/resources/TkResourceDescriptor.h
    ${CMAKE_SOURCE_DIR}/common/resources/TkResourceManager.cpp
    ${CMAKE_SOURCE_DIR}/common/resources/TkResourceManager.h
    ${CMAKE_SOURCE_DIR}/common/resources/TkResourceRegistryEntry.h
    ${CMAKE_SOURCE_DIR}/common/resources/TkSmartResHandle.h
    ${CMAKE_SOURCE_DIR}/common/simulation/TkRigidBodyPtr.h
    ${CMAKE_SOURCE_DIR}/common/simulation/TkSeed.h
    ${CMAKE_SOURCE_DIR}/common/system/AutoPooled.h
    ${CMAKE_SOURCE_DIR}/common/system/thread/TkLockFreeQueue.h
    ${CMAKE_SOURCE_DIR}/common/system/timer/TkClock.h
    ${CMAKE_SOURCE_DIR}/common/system/TkIterationState.h
    ${CMAKE_SOURCE_DIR}/common/utilities/allocators/TkStackAllocator.h
    ${CMAKE_SOURCE_DIR}/common/utilities/allocators/TkSTLAllocator.h
    ${CMAKE_SOURCE_DIR}/common/utilities/containers/TkClassPool.h
    ${CMAKE_SOURCE_DIR}/common/utilities/containers/TkFlatMap.h
    ${CMAKE_SOURCE_DIR}/common/utilities/containers/TkStackContainer.h
    ${CMAKE_SOURCE_DIR}/common/utilities/containers/TkStackVector.h
    ${CMAKE_SOURCE_DIR}/common/utilities/containers/TkVector.h
    ${CMAKE_SOURCE_DIR}/common/utilities/filesystem/TkFileSystem.h
    ${CMAKE_SOURCE_DIR}/common/utilities/pools/TkLinearMemoryPool.h
    ${CMAKE_SOURCE_DIR}/common/utilities/pools/TkMemoryPool.h
    ${CMAKE_SOURCE_DIR}/common/utilities/spookyhash/SpookyV2.cpp
    ${CMAKE_SOURCE_DIR}/common/utilities/spookyhash/SpookyV2.h
    ${CMAKE_SOURCE_DIR}/common/utilities/TkAlignedBlock.h
    ${CMAKE_SOURCE_DIR}/common/utilities/TkArray.h
    ${CMAKE_SOURCE_DIR}/common/utilities/TkLinearHashTable.h
    ${CMAKE_SOURCE_DIR}/common/utilities/TkMemoryManager.h
    ${CMAKE_SOURCE_DIR}/common/utilities/TkString.h
    ${CMAKE_SOURCE_DIR}/common/utilities/TkStrongType.h
    ${CMAKE_SOURCE_DIR}/common/xml/XMLAttribute.h
    ${CMAKE_SOURCE_DIR}/common/xml/XMLClear.h
    ${CMAKE_SOURCE_DIR}/common/xml/XMLNode.h
)

# Thaumium
add_library(
    ThaumiumDLL SHARED
    ${TOOLKIT_SOURCES}
    "dllmain.cpp"
    "dllmain.h"
    "framework.h"
    "source/application/GcApplication.cpp"
    "source/application/GcApplication.h"
    "source/atlas/DownloadType.h"
    "source/atlas/GcAtlasDownloadType.h"
    "source/atlas/GcAtlasTransportWinHttp.h"
    "source/atlas/Http.h"
    "source/atlas/WinHttpTask.h"
    "source/core/commands/commands.h"
    "source/core/core.cpp"
    "source/core/core.h"
    "source/core/globals/application.cpp"
    "source/core/globals/engine.cpp"
    "source/core/globals/globals.h"
    "source/core/globals/hash.h"
    "source/core/globals/lookup.cpp"
    "source/core/globals/metadata.h"
    "source/core/hooks.cpp"
    "source/core/hooks.h"
    "source/core/memory.cpp"
    "source/core/memory.h"
    "source/engine/EgMain.cpp"
    "source/engine/EgMain.h"
    "source/engine/EgModules.h"
    "source/engine/TkEngineUtils.h"
    "source/graphics/AltMode.h"
    "source/graphics/Animate.h"
    "source/graphics/Curve.h"
    "source/graphics/Gradient.h"
    "source/graphics/Horizontal.h"
    "source/graphics/Shape.h"
    "source/graphics/TkCurveType.h"
    "source/graphics/Vertical.h"
    "source/network/GcNetworkManager.h"
    "source/network/GcNetworkMessageManager.h"
    "source/network/GcTextChatInput.h"
    "source/network/GcTextChatManager.h"
    "source/network/GcURL.h"
    ${METADATA_SOURCE}
    ${METADATA_TOOLKIT}
)

target_precompile_headers(ThaumiumDLL PRIVATE pch.h)

target_compile_definitions(ThaumiumDLL PRIVATE VERSION=${CMAKE_PROJECT_VERSION})

if(USEFRACTAL)
    target_compile_definitions(ThaumiumDLL PRIVATE FRACTAL=1)
else()
    target_compile_definitions(ThaumiumDLL PRIVATE UPSTREAM=1)
endif(USEFRACTAL)

target_link_libraries(
    ThaumiumDLL PRIVATE ${CMAKE_SOURCE_DIR}/thirdparty/lib/MinHook.x64.lib
)

target_include_directories(
    ThaumiumDLL PRIVATE ${CMAKE_SOURCE_DIR}/thirdparty/include
)

set_target_properties(ThaumiumDLL PROPERTIES OUTPUT_NAME Thaumium)

# Targets
add_subdirectory(proxy)
add_subdirectory(metadata)
