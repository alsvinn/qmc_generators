
#include "qmc/hammersley_api.h"
#include "qmc/hammersley.hpp"
#include <memory>
#include <iostream>
extern "C" {

HAMMERSLEY_EXPORT double hammersley_generate(void* data, int size, int dimension, int component, int sample) {
     std::shared_ptr<double> dataPointer(hammersley(sample, dimension, size));

     return dataPointer.get()[component];
}

HAMMERSLEY_EXPORT void *hammersley_create(int size, int dimensions) {
    return NULL;
}

HAMMERSLEY_EXPORT void hammersley_delete(void *data) {
    // do nothing
}
}
