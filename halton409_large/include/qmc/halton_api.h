#pragma once
#include "qmc/halton_export.h"

#ifdef __cplusplus
extern "C" {
#endif

HALTON_EXPORT double halton409_large_generate(void* data, int size,
    int dimension, int component, int sample, void* parameters);

HALTON_EXPORT void* halton409_large_create(int size, int dimension,
    void* parameters);

HALTON_EXPORT void halton409_large_delete(void* data);

HALTON_EXPORT void* halton409_large_make_parameters();

HALTON_EXPORT void halton409_large_set_parameter(void* parameters,
    const char* name,
    const char* value);

HALTON_EXPORT void halton409_large_delete_parameters(void* parameters);

#ifdef __cplusplus
}
#endif
