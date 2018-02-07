#pragma once
#include "qmc/latin_random_export.h"

#ifdef __cplusplus
extern "C" {
#endif
LATIN_RANDOM_EXPORT void* latin_random_create(int size, int dimensions);

LATIN_RANDOM_EXPORT double latin_random_generate(void* data, int size, int dimension, int component, int sample);

LATIN_RANDOM_EXPORT void latin_random_delete(void* data);

#ifdef __cplusplus
}
#endif
