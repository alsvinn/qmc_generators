
#include "qmc/latin_center_api.h"
#include "qmc/latin_center.hpp"
#include <memory>
#include <iostream>
extern "C" {

LATIN_CENTER_EXPORT double latin_center_generate(void* data, int size, int dimension, int component, int sample) {
    ((double*)data)[sample*dimension + component];
}

LATIN_CENTER_EXPORT void *latin_center_create(int size, int dimensions) {
    auto data = new double[size*dimensions];
    int seed = 0;
    latin_center(dimensions, size, &seed, data);

    return data;
}

LATIN_CENTER_EXPORT void latin_center_delete(void *data) {
    delete (double*)data;
}
}
