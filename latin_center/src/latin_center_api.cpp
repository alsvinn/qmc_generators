
#include "qmc/latin_center_api.h"
#include "qmc/latin_center.hpp"
#include <memory>
#include <iostream>
extern "C" {

    LATIN_CENTER_EXPORT double latin_center_generate(void* data, int size,
        int dimension, int component, int sample, void*) {
        ((double*)data)[sample * dimension + component];
    }

    LATIN_CENTER_EXPORT void* latin_center_create(int size, int dimensions, void*) {
        auto data = new double[size * dimensions];
        int seed = 1234567;
        latin_center(dimensions, size, &seed, data);

        return data;
    }

    LATIN_CENTER_EXPORT void latin_center_delete(void* data) {
        delete (double*)data;
    }



    LATIN_CENTER_EXPORT void* latin_center_make_parameters() {
        return NULL;

    }

    LATIN_CENTER_EXPORT void latin_center_set_parameter(void* parameters,
        const char* name,
        const char* value) {

    }

    LATIN_CENTER_EXPORT void latin_center_delete_parameters(void* parameters) {

    }
}
