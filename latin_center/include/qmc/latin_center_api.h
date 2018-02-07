#pragma once
#include "qmc/latin_center_export.h"

#ifdef __cplusplus
extern "C" {
#endif
LATIN_CENTER_EXPORT void* latin_center_create(int size, int dimensions);

LATIN_CENTER_EXPORT double latin_center_generate(void* data, int size, int dimension, int component, int sample);

LATIN_CENTER_EXPORT void latin_center_delete(void* data);

#ifdef __cplusplus
}
#endif
