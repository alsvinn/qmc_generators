#pragma once
#include "qmc/hammersley_export.h"

#ifdef __cplusplus
extern "C" {
#endif
HAMMERSLEY_EXPORT void* hammersley_create(int size, int dimensions,
    void* parameters);

HAMMERSLEY_EXPORT double hammersley_generate(void* data, int size,
    int dimension, int component, int sample, void* parameters);

HAMMERSLEY_EXPORT void hammersley_delete(void* data);

HAMMERSLEY_EXPORT void* hammersley_make_parameters();

HAMMERSLEY_EXPORT void hammersley_set_parameter(void* parameters,
    const char* name,
    const char* value);

HAMMERSLEY_EXPORT void hammersley_delete_parameters(void* parameters);

#ifdef __cplusplus
}
#endif
