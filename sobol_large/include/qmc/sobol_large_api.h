#pragma once
#include "qmc/sobol_export.h"

#ifdef __cplusplus
extern "C" {
#endif
SOBOL_EXPORT void* sobol_large_create(int size, int dimensions, void*);

SOBOL_EXPORT double sobol_large_generate(void* data, int size, int dimension,
    int component, int sample, void* parameters);

SOBOL_EXPORT void sobol_large_delete(void* data);


SOBOL_EXPORT void* sobol_large_make_parameters();

SOBOL_EXPORT void sobol_large_set_parameter(void* parameters,
    const char* name,
    const char* value);

SOBOL_EXPORT void sobol_large_delete_parameters(void* parameters);

#ifdef __cplusplus
}
#endif
