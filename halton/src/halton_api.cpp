#include "qmc/halton_api.h"
#include "qmc/halton.hpp"
#include <memory>
#include <iostream>
extern "C" {

    HALTON_EXPORT double halton_generate(void* data, int size, int dimension,
        int component, int sample, void* parameters) {
        // Yes, this is a bit inefficient, but usually, this is not the large time cost
        std::shared_ptr<double> haltonSample(halton(sample, dimension));
        return haltonSample.get()[component];
    }




    void* halton_create(int size, int dimension, void* parameters) {
        return NULL;
    }

    void halton_delete(void* data) {
        // do nothing
    }

    HALTON_EXPORT void* halton_make_parameters() {
        return NULL;
    }

    HALTON_EXPORT void halton_set_parameter(void* parameters,
        const char* name,
        const char* value) {

    }

    HALTON_EXPORT void halton_delete_parameters(void* parameters) {

    }

}
