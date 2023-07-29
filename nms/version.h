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
