#include "qmc/halton_api.h"
#include "qmc/halton.hpp"
#include <memory>
#include <iostream>
extern "C" {

HALTON_EXPORT double halton_generate(void* data, int size, int dimension, int component, int sample) {
  // Yes, this is a bit inefficient, but usually, this is not the large time cost
  std::shared_ptr<double> haltonSample(halton(sample, dimension));
  return haltonSample.get()[component];
}


}
