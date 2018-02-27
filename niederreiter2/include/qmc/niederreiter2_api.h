#pragma once
#include "qmc/niederreiter2_export.h"

#ifdef __cplusplus
extern "C" {
#endif
NIEDERREITER2_EXPORT void* niederreiter2_create(int size, int dimensions,
    void*);

NIEDERREITER2_EXPORT double niederreiter2_generate(void* data, int size,
    int dimension, int component, int sample, void*);

NIEDERREITER2_EXPORT void niederreiter2_delete(void* data);



NIEDERREITER2_EXPORT void* niederreiter2_make_parameters();

NIEDERREITER2_EXPORT void niederreiter2_set_parameter(void* parameters,
    const char* name,
    const char* value);

NIEDERREITER2_EXPORT void niederreiter2_delete_parameters(void* parameters);

#ifdef __cplusplus
}
#endif
