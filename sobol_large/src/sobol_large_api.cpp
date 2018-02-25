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
        int component, int sample) {
        return ((std::vector<double>*)data)->at(sample * dimension + component);
    }

    SOBOL_EXPORT void* sobol_large_create(int size, int dimensions) {
        auto output = exec ("./sobol " + std::to_string(size) + " "
                + std::to_string(dimensions) + " dataset.txt");

        std::istringstream stream(output);
        std::vector<double>* points = new std::vector<double>;
        points->reserve(size * dimensions);

        double point;

        while ( stream >> point) {
            points->push_back(point);
        }

        return (void*)points;
    }

    SOBOL_EXPORT void sobol_large_delete(void* data) {
        delete (std::vector<double>*)data;
    }
}
