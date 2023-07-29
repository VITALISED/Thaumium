#pragma once

// This file is for managing different builds and versions. 
// Right now this doesn't do anything but I'll be adding specific version targets at some point
// Below is some example naming schemes

#if FRACTAL
#define NMS_FRACTAL_101263
#endif

#if UPSTREAM
#define NMS_UPSTREAM
#define NMS_SINGULARITY_107985
#endif

#define GCAPPLICATION (cGcApplication*)OFFSET(0x463F810)
