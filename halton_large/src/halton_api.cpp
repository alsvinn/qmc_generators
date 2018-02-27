#include "qmc/halton_api.h"
#include "qmc/halton.hpp"
#include <memory>
#include <iostream>
#include <map>
#include <fstream>
#define HALTON_SIZE_LIMIT 32*1024*1024
extern "C" {

    HALTON_EXPORT void* halton_large_create(int size, int dimension,
        void* parameters) {

        auto parameter_map = reinterpret_cast<std::map<std::string, std::string>*>
            (parameters);

        // We try to allocate it in memory, when that fails, we use the disk
        try {
            if (size * dimension >= HALTON_SIZE_LIMIT) {
                throw std::bad_alloc();
            }

            double* data =  halton_sequence(0, size - 1, dimension);
            parameter_map->operator []("halton_type") = "memory";
            return (void*)data;
        } catch (std::bad_alloc&) {
            // Now we need the mpi node


            auto mpi_node = std::stoi(parameter_map->at("mpi_node"));

            if (mpi_node == 0) {
                std::ofstream file("halton_sequence.bin", std::ios::out | std::ios::binary);

                for (int sample = 0; sample < size; ++sample) {
                    double* halton_sample_vector = halton(sample, dimension);


                    file.write((char*)halton_sample_vector, sizeof(double)*dimension);
                }
            }

            parameter_map->operator []("halton_type") = "disk";

            return new double[1];
        }
    }

    HALTON_EXPORT double haltonlarge_generate(void* data, int size,
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



    HALTON_EXPORT void halton_large_delete(void* data) {
        delete[] (double*)data;
    }


    HALTON_EXPORT void* halton_large_make_parameters() {
        return new std::map<std::string, std::string>();
    }

    HALTON_EXPORT void halton_large_set_parameter(void* parameters,
        const char* name,
        const char* value) {
        reinterpret_cast<std::map<std::string, std::string>*>(parameters)->operator [](
            name) = value;
    }

    HALTON_EXPORT void halton_large_delete_parameters(void* parameters) {
        delete reinterpret_cast<std::map<std::string, std::string>*>(parameters);
    }
}
