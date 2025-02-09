#include "midterm.h"

#include<math.h>
#include <stdio.h>

double *exponents(int start, int end, double power) {
  double *return_array = (double *)malloc(sizeof(double) * (end - start + 1));
  for(int i = 0; i <= end - start; i++){
    double current = start + i;
    return_array[i] = pow(current, power);
  }
  return return_array;
}
