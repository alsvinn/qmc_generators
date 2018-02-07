
#include "qmc/sobol_api.h"
#include "qmc/sobol.hpp"
#include <memory>
#include <iostream>
extern "C" {

SOBOL_EXPORT double sobol_generate(void* data, int size, int dimension, int component, int sample) {
    return ((double*)data)[sample*dimension + component];
}

SOBOL_EXPORT void *sobol_create(int size, int dimensions) {
    return (void*)(i8_sobol_generate(dimensions, size, 0));
}

SOBOL_EXPORT void sobol_delete(void *data) {
    delete (double*)data;
}
}
