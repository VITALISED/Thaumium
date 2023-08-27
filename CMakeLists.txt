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

# Thaumium
add_library(
    ThaumiumDLL SHARED
    "common/attachments/TkHandle.h"
    "common/graphics/TkColour.h"
    "common/maths/TkAABB.h"
    "common/maths/TkBBox2d.h"
    "common/maths/TkMatrix34.h"
    "common/maths/TkPhysRelVec3.h"
    "common/maths/TkVector2.h"
    "common/maths/TkVector3.h"
    "common/maths/TkVector4.h"
    "common/metadata/TkClassPointer.h"
    "common/metadata/TkID.h"
    "common/resources/TkResource.h"
    "common/resources/TkResourceDescriptor.h"
    "common/resources/TkResourceManager.cpp"
    "common/resources/TkResourceManager.h"
    "common/simulation/TkRigidBodyPtr.h"
    "common/simulation/TkSeed.h"
    "common/system/AutoPooled.h"
    "common/system/thread/TkLockFreeQueue.h"
    "common/system/timer/TkClock.h"
    "common/system/TkIterationState.h"
    "common/utilities/allocators/TkStackAllocator.h"
    "common/utilities/allocators/TkSTLAllocator.h"
    "common/utilities/containers/TkStackContainer.h"
    "common/utilities/containers/TkStackVector.h"
    "common/utilities/containers/TkVector.h"
    "common/utilities/filesystem/FileOpenMode.h"
    "common/utilities/filesystem/FIOS2HANDLE.h"
    "common/utilities/filesystem/TkFileSystem.h"
    "common/utilities/pools/TkLinearMemoryPool.h"
    "common/utilities/pools/TkMemoryPool.h"
    "common/utilities/spookyhash/SpookyV2.cpp"
    "common/utilities/spookyhash/SpookyV2.h"
    "common/utilities/TkAlignedBlock.h"
    "common/utilities/TkArray.h"
    "common/utilities/TkLinearHashTable.h"
    "common/utilities/TkMemoryManager.h"
    "common/utilities/TkString.h"
    "common/utilities/TkStrongType.h"
    "common/xml/XMLAttribute.h"
    "common/xml/XMLClear.h"
    "common/xml/XMLNode.h"
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
    "source/core/core.cpp"
    "source/core/core.h"
    "source/core/globals/lookup.cpp"
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
