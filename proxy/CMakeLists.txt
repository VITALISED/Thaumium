add_library(ThaumiumProxy SHARED
	"dllmain.cpp"
	"framework.h"
	"exports.h"
)

target_precompile_headers(ThaumiumProxy PRIVATE pch.h)

set_target_properties(ThaumiumProxy PROPERTIES
                      OUTPUT_NAME version
)