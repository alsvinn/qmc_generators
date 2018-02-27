#include "qmc/halton_api.h"
#include "qmc/halton.hpp"
#include <memory>
#include <iostream>
extern "C" {


    HALTON_EXPORT double halton409_generate(void* data, int size, int dimension,
        int component, int sample, void* parameters) {
        // Yes, this is a bit inefficient, but usually, this is not the large time cost
        std::shared_ptr<double> haltonSample(halton(409 * sample, dimension));
        return haltonSample.get()[component];
    }




    void* halton409_create(int size, int dimension, void* parameters) {
        return NULL;
    }

    void halton409_delete(void* data) {
        // do nothing
    }

    HALTON_EXPORT void* halton409_make_parameters() {
        return NULL;
    }

    HALTON_EXPORT void halton409_set_parameter(void* parameters,
        const char* name,
        const char* value) {

    }

    HALTON_EXPORT void halton409_delete_parameters(void* parameters) {

    }

}
