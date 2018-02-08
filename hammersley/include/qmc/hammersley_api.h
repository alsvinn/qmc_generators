#pragma once
#include "qmc/hammersley_export.h"

#ifdef __cplusplus
extern "C" {
#endif
HAMMERSLEY_EXPORT void* hammersley_create(int size, int dimensions);

HAMMERSLEY_EXPORT double hammersley_generate(void* data, int size, int dimension, int component, int sample);

HAMMERSLEY_EXPORT void hammersley_delete(void* data);

#ifdef __cplusplus
}
#endif
