
#include "qmc/hammersley_api.h"
#include "qmc/hammersley.hpp"
#include <memory>
#include <iostream>
extern "C" {

    HAMMERSLEY_EXPORT double hammersley_generate(void* data, int size,
        int dimension, int component, int sample, void*) {
        std::shared_ptr<double> dataPointer(hammersley(sample, dimension, size));

        return dataPointer.get()[component];
    }

    HAMMERSLEY_EXPORT void* hammersley_create(int size, int dimensions, void*) {
        return NULL;
    }

    HAMMERSLEY_EXPORT void hammersley_delete(void* data) {
        // do nothing
    }


    HAMMERSLEY_EXPORT void* hammersley_make_parameters() {
        return NULL;
    }

    HAMMERSLEY_EXPORT void hammersley_set_parameter(void* parameters,
        const char* name,
        const char* value) {

    }

    HAMMERSLEY_EXPORT void hammersley_delete_parameters(void* parameters) {

    }
}
