#include "generator.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
int main(int argc, char** argv) {
  if (argc != 4) {
    std::cout << "Usage:\n\t" << argv[0] << " generator <dimensions> <number of samples>" << std::endl;
    return EXIT_FAILURE;
  }
  
  std::cout << std::setprecision(std::numeric_limits<long double>::digits10 + 1);

  int dimension = std::atoi(argv[2]);
  int samples = std::atoi(argv[3]);
  Generator generator(argv[1]);

  auto parameters = generator.make_parameters_function();
   generator.set_parameter_function(parameters, "mpi_node",
            "0");
        generator.set_parameter_function(parameters, "mpi_size",
            "1");
	
	auto data = generator.create_function(samples, dimension, parameters);

  std::cout << samples << std::endl;

  for (int k = 0; k < samples; ++k) {
    for (int d = 0; d < dimension; ++d) {
      std::cout << generator.generate_function(data, samples, dimension, d, k, parameters) << " ";
    }
    std::cout << std::endl;
  }
  
}
