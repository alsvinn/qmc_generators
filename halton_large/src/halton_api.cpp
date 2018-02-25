#include "qmc/halton_large_api.h"
#include "qmc/halton_large.hpp"
#include <memory>
#include <iostream>
extern "C" {

HALTON_EXPORT double halton_large_generate(void* data, int size, int dimension, int component, int sample) {
  // Yes, this is a bit inefficient, but usually, this is not the large time cost
 //   std::cout << "size = " << size << std::endl;
 //   std::cout << "dimension = " << dimension << std::endl;
 //   std::cout << "component = " << component << std::endl;
 //   std::cout << "sample = " << sample << std::endl;
  std::shared_ptr<double> halton_largeSample(halton_large(sample, dimension));
  return halton_largeSample.get()[component];
}


}

void *halton_large_create(int size, int dimension)
{
    return NULL;
}

void halton_large_delete(void *data)
{
    // do nothing
}
