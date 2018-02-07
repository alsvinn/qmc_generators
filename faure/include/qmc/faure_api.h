#pragma once
#include "qmc/faure_export.h"

#ifdef __cplusplus
extern "C" {
#endif
FAURE_EXPORT void* faure_create(int size, int dimensions);

FAURE_EXPORT double faure_generate(void* data, int size, int dimension, int component, int sample);

FAURE_EXPORT void faure_delete(void* data);

#ifdef __cplusplus
}
#endif
        