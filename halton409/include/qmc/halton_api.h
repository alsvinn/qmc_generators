#pragma once
#include "qmc/halton_export.h"

#ifdef __cplusplus
extern "C" {
#endif

HALTON_EXPORT double halton409_generate(void* data, int size, int dimension, int component, int sample);

HALTON_EXPORT void* halton409_create(int size, int dimension);

HALTON_EXPORT void halton409_delete(void* data);


#ifdef __cplusplus
}
#endif
