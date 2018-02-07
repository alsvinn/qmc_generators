#pragma once
#include "qmc/halton_export.h"

#ifdef __cplusplus
extern "C" {
#endif

HALTON_EXPORT double halton_generate(void* data, int size, int dimension, int component, int sample);



#ifdef __cplusplus
}
#endif
