#include "qmc/halton_api.h"
#include "qmc/halton.hpp"
#include <memory>
#include <iostream>
#include <fstream>
#include <map>
#define HALTON_SIZE_LIMIT 16*128*128

namespace {
void* make_halton_sequence(int size, int dimension) {
    double* halton_sequence = new double[size * dimension];

    for (int sample = 0; sample < size; ++sample) {
        double* halton_sample_vector = halton(409 * sample, dimension);

        for (int component = 0; component < dimension; ++component) {
            halton_sequence[sample * dimension + component] =
                halton_sample_vector[component];
        }

        delete[] halton_sample_vector;
    }

    return (void*)halton_sequence;
}
}

extern "C" {


    HALTON_EXPORT double halton409_large_generate(void* data, int size,
        int dimension, int component, int sample, void* parameters) {

        auto parameter_map = reinterpret_cast<std::map<std::string, std::string>*>
            (parameters);


        auto halton_type = parameter_map->at("halton_type");

        if (halton_type == "memory") {
            return ((double*)data)[sample * dimension + component];
        } else {
            double point;

            std::ifstream sequence_file("halton_sequence.bin", std::ios::binary);

            sequence_file.read((char*)&point,
                sizeof(double) * (sample * dimension + component));

            return point;
        }
    }




    void* halton409_large_create(int size, int dimension, void* parameters) {

        auto parameter_map = reinterpret_cast<std::map<std::string, std::string>*>
            (parameters);

        // We try to allocate it in memory, when that fails, we use the disk
        try {
            if (size * dimension >= HALTON_SIZE_LIMIT) {
                throw std::bad_alloc();
            }

            void* data = make_halton_sequence(size, dimension);
            parameter_map->operator []("halton_type") = "memory";

            return data;
        } catch (std::bad_alloc&) {
            // Now we need the mpi node


            auto mpi_node = std::stoi(parameter_map->at("mpi_node"));

            if (mpi_node == 0) {
                std::ofstream file("halton_sequence.bin", std::ios::out | std::ios::binary);

                for (int sample = 0; sample < size; ++sample) {
                    double* halton_sample_vector = halton(409 * sample, dimension);


                    file.write((char*)halton_sample_vector, sizeof(double)*dimension);
                }
            }

            parameter_map->operator []("halton_type") = "disk";

            return new double[1];
        }
    }

    void halton409_large_delete(void* data) {
        delete[] (double*)data;
    }

    void* halton409_large_make_parameters() {
        return new std::map<std::string, std::string>();
    }

    void halton409_large_set_parameter(void* parameters, const char* name,
        const char* value) {
        reinterpret_cast<std::map<std::string, std::string>*>(parameters)->operator [](
            name) = value;
    }

    void halton409_large_delete_parameters(void* parameters) {
        delete reinterpret_cast<std::map<std::string, std::string>*>(parameters);
    }
}
