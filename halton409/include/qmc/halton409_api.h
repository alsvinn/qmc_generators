#pragma once
#include "qmc/halton409_export.h"

#ifdef __cplusplus
extern "C" {
#endif

HALTON409_EXPORT double halton409_generate(void* data, int size, int dimension,
    int component, int sample, void* parameters);

HALTON409_EXPORT void* halton409_create(int size, int dimension, void* parameters);

HALTON409_EXPORT void halton409_delete(void* data);

HALTON409_EXPORT void* halton409_make_parameters();

HALTON409_EXPORT void halton409_set_parameter(void* parameters,
    const char* name,
    const char* value);

HALTON409_EXPORT void halton409_delete_parameters(void* parameters);
#ifdef __cplusplus
}
#endif
