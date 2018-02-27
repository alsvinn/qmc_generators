
#include "qmc/niederreiter2_api.h"
#include "qmc/niederreiter2.hpp"
#include <memory>
#include <iostream>
extern "C" {

    NIEDERREITER2_EXPORT double niederreiter2_generate(void* data, int size,
        int dimension, int component, int sample, void*) {
        return ((double*)data)[sample * dimension + component];
    }

    NIEDERREITER2_EXPORT void* niederreiter2_create(int size, int dimensions,
        void*) {
        int seed = 0;
        return (void*)niederreiter2::niederreiter2_generate(dimensions, size, &seed);
    }

    NIEDERREITER2_EXPORT void niederreiter2_delete(void* data) {
        delete (double*)data;
    }


    NIEDERREITER2_EXPORT void* niederreiter2_make_parameters() {
        return NULL;

    }

    NIEDERREITER2_EXPORT void niederreiter2_set_parameter(void* parameters,
        const char* name,
        const char* value) {

    }

    NIEDERREITER2_EXPORT void niederreiter2_delete_parameters(void* parameters) {

    }
}
