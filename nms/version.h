#pragma once

// This file is primarly for managing offsets and signatures for specific calls I can't really reimplement/too lazy to.
// Not all of them are using this format at the moment (namely my fairly outdated NGui code), however should be fixed at some point.

#if FRACTAL
#define NMS_FRACTAL_101263
#endif

#if UPSTREAM
#define NMS_UPSTREAM
#define NMS_SINGULARITY_107985
#endif

#define GCAPPLICATION (cGcApplication*)OFFSET(0x463F810)

// Double check this constant is used in other places
#define HASH_SEED 0x72C085E2EE7C6F27 
// Not sure on this one either
#define DEFAULT_HASH 0x1D39488B798170F