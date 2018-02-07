#pragma once
#include "qmc/sobol_export.h"

#ifdef __cplusplus
extern "C" {
#endif
SOBOL_EXPORT void* sobol_create(int size, int dimensions);

SOBOL_EXPORT double sobol_generate(void* data, int size, int dimension, int component, int sample);

SOBOL_EXPORT void sobol_delete(void* data);

#ifdef __cplusplus
}
#endif
