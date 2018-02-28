#pragma once
#include "qmc/faure_export.h"

#ifdef __cplusplus
extern "C" {
#endif
FAURE_EXPORT void* faure_create(int size, int dimensions, void* parameters);

FAURE_EXPORT double faure_generate(void* data, int size, int dimension,
    int component, int sample, void* parameters);

FAURE_EXPORT void faure_delete(void* data);

FAURE_EXPORT void* faure_make_parameters();

FAURE_EXPORT void faure_set_parameter(void* parameters,
    const char* name,
    const char* value);

FAURE_EXPORT void faure_delete_parameters(void* parameters);

#ifdef __cplusplus
}
#endif
