#include "qmc/sobol_export.h"
#include "qmc/sobol_large_api.h"

#include <memory>
#include <iostream>
#include <vector>

#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <sstream>
#include <fstream>
#include <string>
#include <array>
#include <map>
// We only want to store maximum 128 MB
#define SOBOL_SIZE_LIMIT (128*1024*1024/8)
#define SOBOL_OUTPUT_FILE "sobol_sequence.bin"
namespace {
std::string exec(const std::string& cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::shared_ptr<FILE> pipe(popen(cmd.c_str(), "r"), pclose);

    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }

    while (!feof(pipe.get())) {
        if (fgets(buffer.data(), 128, pipe.get()) != nullptr) {
            result += buffer.data();
        }
    }

    return result;
}

}

extern "C" {

    SOBOL_EXPORT double sobol_large_generate(void* data, int size, int dimension,
        int component, int sample, void*) {
        if (size * dimension < SOBOL_SIZE_LIMIT ) {
            return ((std::vector<double>*)data)->at(sample * dimension + component);
        } else {
            std::ifstream input_file(SOBOL_OUTPUT_FILE, std::ios::binary);

            double point;

            input_file.read((char*)&point,
                sizeof(double) * (sample * dimension + component));

            return point;
        }
    }

    SOBOL_EXPORT void* sobol_large_create(int size, int dimensions,
        void* parameters) {


        if (size * dimensions < SOBOL_SIZE_LIMIT ) {
            std::string command_to_execute = "./sobol " + std::to_string(size) + " "
                + std::to_string(dimensions) + " dataset.txt";
            auto output = exec (command_to_execute);

            std::istringstream stream(output);
            std::vector<double>* points = new std::vector<double>;
            points->reserve(size * dimensions);

            double point;

            while ( stream >> point) {
                points->push_back(point);
            }

            return (void*)points;
        } else {
            // Now we need the mpi node
            auto parameter_map = reinterpret_cast<std::map<std::string, std::string>*>
                (parameters);



            auto mpi_node = std::stoi(parameter_map->at("mpi_node"));

            if (mpi_node == 0) {
                std::string command_to_execute = "./sobol_binary " + std::to_string(size) + " "
                    + std::to_string(dimensions) + " dataset.txt";
                std::system(command_to_execute.c_str());
            }

            return new std::vector<double>(1);
        }
    }

    SOBOL_EXPORT void sobol_large_delete(void* data) {
        delete (std::vector<double>*)data;
    }

    SOBOL_EXPORT void* sobol_large_make_parameters() {
        return new std::map<std::string, std::string>();

    }

    SOBOL_EXPORT void sobol_large_set_parameter(void* parameters,
        const char* name,
        const char* value) {
        reinterpret_cast<std::map<std::string, std::string>*>(parameters)->operator [](
            name) = value;

    }

    SOBOL_EXPORT void sobol_large_delete_parameters(void* parameters) {
        delete (std::map<std::string, std::string>*)parameters;
    }
}
