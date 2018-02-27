#include "qmc/halton_api.h"
#include "qmc/halton.hpp"
#include <memory>
#include <iostream>
extern "C" {


HALTON_EXPORT double halton409_large_generate(void* data, int size, int dimension, int component, int sample) {
  return ((double*)data)[sample * dimension + component];
}


}

void *halton409_large_create(int size, int dimension)
{
  double* halton_sequence = new double[size*dimension];

  for (int sample = 0; sample < size; ++sample) {
    double* halton_sample_vector = halton(409*sample, dimension);
    for (int component = 0; component < dimension; ++component) {
      halton_sequence[sample*dimension + component] = halton_sample_vector[component];
    }

    delete[] halton_sample_vector;
  }

  return (void*)halton_sequence;
}

void halton409_large_delete(void *data)
{
  delete[] (double*)data;
}
