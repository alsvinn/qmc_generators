#include "qmc/latin_random_api.h"
#include "qmc/latin_random.hpp"
#include <memory>
#include <iostream>
extern "C" {

LATIN_RANDOM_EXPORT double latin_random_generate(void* data, int size, int dimension, int component, int sample) {
    return ((double*)data)[sample*dimension + component];
}

LATIN_RANDOM_EXPORT void *latin_random_create(int size, int dimensions)
{
    int seed = 1234567;
    auto random_numbers = latin_random_new ( dimensions, size, seed );

    return (void*)random_numbers;
}

LATIN_RANDOM_EXPORT void latin_random_delete(void *data)
{
    delete[] (double*)data;
}

}
