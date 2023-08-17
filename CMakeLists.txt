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

# Thaumium
add_library(
    ThaumiumDLL SHARED
    "application/GcApplication.cpp"
    "application/GcApplication.h"
    "atlas/DownloadType.h"
    "atlas/GcAtlasDownloadType.h"
    "atlas/GcAtlasTransportWinHttp.h"
    "atlas/Http.h"
    "atlas/WinHttpTask.h"
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
    "common/utilities/spookyhash/SpookyV2.cpp"
    "common/utilities/spookyhash/SpookyV2.h"
    "common/utilities/TkAlignedBlock.h"
    "common/utilities/TkArray.h"
    "common/utilities/TkLinearHashTable.h"
    "common/utilities/TkLinearMemoryPool.h"
    "common/utilities/TkMemoryManager.h"
    "common/utilities/TkMemoryPool.h"
    "common/utilities/TkString.h"
    "common/utilities/TkStrongType.h"
    "common/xml/XMLAttribute.h"
    "common/xml/XMLClear.h"
    "common/xml/XMLNode.h"
    "core/core.cpp"
    "core/core.h"
    "dllmain.cpp"
    "dllmain.h"
    "engine/EgMain.cpp"
    "engine/EgMain.h"
    "engine/EgModules.h"
    "engine/TkEngineUtils.h"
    "framework.h"
    "graphics/AltMode.h"
    "graphics/Animate.h"
    "graphics/Curve.h"
    "graphics/Gradient.h"
    "graphics/Horizontal.h"
    "graphics/Shape.h"
    "graphics/TkCurveType.h"
    "graphics/Vertical.h"
    "network/GcNetworkManager.h"
    "network/GcNetworkMessageManager.h"
    "network/GcTextChatInput.h"
    "network/GcTextChatManager.h"
    "simulation/CentreJourneyDestination.h"
    "simulation/DiscoveryAutoSync.h"
    "simulation/GcSceneManager.h"
    "simulation/GcSimulation.h"
    "simulation/particles/GcParticleManager.h"
    "simulation/particles/HeavyAirType.h"
    "simulation/player/GcAvailableWeapons.h"
    "simulation/player/GcPlayer.h"
    "simulation/player/GcPlayerControlInput.cpp"
    "simulation/player/GcPlayerControlInput.h"
    "simulation/player/GcPlayerRespawn.h"
    "simulation/player/GcPlayerSpawnState.h"
    "simulation/solarsystem/asteroid/GcAstroidGeneratorRing.h"
    "simulation/solarsystem/GcGalacticSolarSystemAddress.h"
    "simulation/solarsystem/GcGalaticVoxelCoordinate.h"
    "simulation/solarsystem/GcSolarSystem.h"
    "simulation/solarsystem/GcSolarSystemAstroidFields.h"
    "simulation/solarsystem/GcSolarSystemDirector.h"
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
                        ${CMAKE_SOURCE_DIR}/thirdparty/lib/Heridium.lib
)

target_include_directories(
    ThaumiumDLL PRIVATE ${CMAKE_SOURCE_DIR}/thirdparty/include
)

set_target_properties(ThaumiumDLL PROPERTIES OUTPUT_NAME Thaumium)

# Targets
add_subdirectory(proxy)
