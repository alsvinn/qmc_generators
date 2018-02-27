#pragma once
#include "qmc/latin_center_export.h"

#ifdef __cplusplus
extern "C" {
#endif
LATIN_CENTER_EXPORT void* latin_center_create(int size, int dimensions, void*);

LATIN_CENTER_EXPORT double latin_center_generate(void* data, int size,
    int dimension, int component, int sample, void*);

LATIN_CENTER_EXPORT void latin_center_delete(void* data);

LATIN_CENTER_EXPORT void* latin_center_make_parameters();

LATIN_CENTER_EXPORT void latin_center_set_parameter(void* parameters,
    const char* name,
    const char* value);

LATIN_CENTER_EXPORT void latin_center_delete_parameters(void* parameters);


#ifdef __cplusplus
}
#endif
