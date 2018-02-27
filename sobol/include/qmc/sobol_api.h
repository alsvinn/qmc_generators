#pragma once
#include "qmc/sobol_export.h"

#ifdef __cplusplus
extern "C" {
#endif
SOBOL_EXPORT void* sobol_create(int size, int dimensions, void*);

SOBOL_EXPORT double sobol_generate(void* data, int size, int dimension,
    int component, int sample, void*);

SOBOL_EXPORT void sobol_delete(void* data);

SOBOL_EXPORT void* sobol_make_parameters();

SOBOL_EXPORT void sobol_set_parameter(void* parameters,
    const char* name,
    const char* value);

SOBOL_EXPORT void sobol_delete_parameters(void* parameters);

#ifdef __cplusplus
}
#endif
