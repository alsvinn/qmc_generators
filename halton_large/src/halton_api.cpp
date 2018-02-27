#include "qmc/halton_api.h"
#include "qmc/halton.hpp"
#include <memory>
#include <iostream>
extern "C" {

HALTON_EXPORT double halton_large_generate(void* data, int size, int dimension, int component, int sample) {

  return ((double*)data)[dimension*sample + component];
}


}

void *halton_large_create(int size, int dimension)
{
  return (void*)halton_sequence(0, size, dimension);
}

void halton_large_delete(void *data)
{
  delete[] (double*)data;
}
