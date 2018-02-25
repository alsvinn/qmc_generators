#pragma once
#include "qmc/halton_export.h"

#ifdef __cplusplus
extern "C" {
#endif

HALTON_EXPORT double halton409_large_generate(void* data, int size, int dimension, int component, int sample);

HALTON_EXPORT void* halton409_large_create(int size, int dimension);

HALTON_EXPORT void halton409_large_delete(void* data);


#ifdef __cplusplus
}
#endif
