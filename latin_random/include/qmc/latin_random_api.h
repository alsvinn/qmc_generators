#pragma once
#include "qmc/latin_random_export.h"

#ifdef __cplusplus
extern "C" {
#endif
LATIN_RANDOM_EXPORT void* latin_random_create(int size, int dimensions, void*);

LATIN_RANDOM_EXPORT double latin_random_generate(void* data, int size,
    int dimension, int component, int sample, void*);

LATIN_RANDOM_EXPORT void latin_random_delete(void* data);



LATIN_RANDOM_EXPORT void* latin_random_make_parameters();

LATIN_RANDOM_EXPORT void latin_random_set_parameter(void* parameters,
    const char* name,
    const char* value);

LATIN_RANDOM_EXPORT void latin_random_delete_parameters(void* parameters);

#ifdef __cplusplus
}
#endif
