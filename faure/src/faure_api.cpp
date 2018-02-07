
#include "qmc/faure_api.h"
#include "qmc/faure.hpp"
#include <memory>
#include <iostream>
extern "C" {

FAURE_EXPORT double faure_generate(void* data, int size, int dimension, int component, int sample) {
    return ((double*)data)[sample * dimension + component];
}

FAURE_EXPORT void *faure_create(int size, int dimensions) {
    return (void*)faure::faure_generate(dimensions, size, 0);
}

FAURE_EXPORT void faure_delete(void *data) {
    delete (double*) data;
}

}
