# Metadata
add_library(
    Heridium
    "dllmain.cpp"
    "dump.cpp"
    "dump.h"
    "framework.h"
    "hooks.cpp"
    "hooks.h"
    "memory.cpp"
    "memory.h"
    "paths.h"
)

target_include_directories(
    Heridium PRIVATE ${CMAKE_SOURCE_DIR}/thirdparty/include
)

target_link_libraries(
    Heridium PRIVATE ${CMAKE_SOURCE_DIR}/thirdparty/lib/MinHook.x64.lib
)

target_precompile_headers(Heridium PRIVATE pch.h)

set_target_properties(Heridium PROPERTIES OUTPUT_NAME Heridium)
