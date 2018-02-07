#pragma once
#include "qmc/niederreiter2_export.h"

#ifdef __cplusplus
extern "C" {
#endif
NIEDERREITER2_EXPORT void* niederreiter2_create(int size, int dimensions);

NIEDERREITER2_EXPORT double niederreiter2_generate(void* data, int size, int dimension, int component, int sample);

NIEDERREITER2_EXPORT void niederreiter2_delete(void* data);

#ifdef __cplusplus
}
#endif
