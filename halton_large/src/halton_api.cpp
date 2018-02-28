#include "qmc/halton_api.h"
#include "qmc/halton.hpp"
#include <memory>
#include <iostream>
#include <map>
#include <fstream>
#define HALTON_SIZE_LIMIT 32*1024*1024
namespace {
std::string make_buffer_filename(int mpi_node, int mpi_size, int size,
    int dimension) {
    return "halton_cache_" + std::to_string(mpi_node) + "_" + std::to_string(
            size) + "_" +
        std::to_string(dimension)
        + ".bin";
}
}

extern "C" {


    HALTON_EXPORT double halton_large_generate(void* data, int size,
        int dimension, int component, int sample, void* parameters) {

        auto parameter_map = reinterpret_cast<std::map<std::string, std::string>*>
            (parameters);


        auto halton_type = parameter_map->at("halton_type");

        if (halton_type == "memory") {
            return ((double*)data)[sample * dimension + component];
        } else {

            // First we find the node that computed it
            const int mpi_size = std::stoi(parameter_map->at("mpi_size"));

            const int samples_per_node = (size + mpi_size - 1) / mpi_size;

            const int mpi_node = sample / samples_per_node;

            const int sample_start = samples_per_node * mpi_node;
            const std::string filename = make_buffer_filename(mpi_node, mpi_size,
                    size, dimension);
            std::ifstream sequence_file(filename, std::ios::binary);


            double point;
            sequence_file.seekg(sizeof(double) * ((sample - sample_start) * dimension +
                    component));
            sequence_file.read((char*)&point, sizeof(double));


            return point;
        }
    }




    void* halton_large_create(int size, int dimension, void* parameters) {

        auto parameter_map = reinterpret_cast<std::map<std::string, std::string>*>
            (parameters);

        // We try to allocate it in memory, when that fails, we use the disk
        try {
            if (size * dimension >= HALTON_SIZE_LIMIT) {
                throw std::bad_alloc();
            }

            void* data = (void*)halton_sequence(0, size - 1, dimension);
            parameter_map->operator []("halton_type") = "memory";

            return data;
        } catch (std::bad_alloc&) {
            // Now we need the mpi node


            auto mpi_node = std::stoi(parameter_map->at("mpi_node"));
            auto mpi_size = std::stoi(parameter_map->at("mpi_size"));

            auto output_filename = make_buffer_filename(mpi_node, mpi_size, size,
                    dimension);

            std::ofstream file(output_filename.c_str(), std::ios::out | std::ios::binary);

            const int samples_per_node = (size + mpi_size - 1) / mpi_size;

            const int sample_start = samples_per_node * mpi_node;
            const int sample_end = std::min(samples_per_node * (mpi_node + 1), size);


            for (int sample = sample_start; sample < sample_end; ++sample) {

                std::unique_ptr<double> halton_sample_vector (halton(sample, dimension));


                file.write((char*)halton_sample_vector.get(), sizeof(double)*dimension);
            }


        }

        parameter_map->operator []("halton_type") = "disk";

        return new double[1];
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
