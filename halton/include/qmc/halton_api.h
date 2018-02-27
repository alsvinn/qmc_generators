#pragma once
#include "qmc/halton_export.h"

#ifdef __cplusplus
extern "C" {
#endif

HALTON_EXPORT double halton_generate(void* data, int size, int dimension,
    int component, int sample, void* parameters);

HALTON_EXPORT void* halton_create(int size, int dimension, void* parameters);

HALTON_EXPORT void halton_delete(void* data);

HALTON_EXPORT void* halton_make_parameters();

HALTON_EXPORT void halton_set_parameter(void* parameters,
    const char* name,
    const char* value);

HALTON_EXPORT void halton_delete_parameters(void* parameters);

#ifdef __cplusplus
}
#endif
