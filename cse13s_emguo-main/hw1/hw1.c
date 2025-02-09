#include "hw1.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

// For the value of Pi, please use M_PI, which is defined in math.h.
double area_of_disk(double radius) {
  return M_PI * radius * radius;
  return 0;
}

double area_of_ring(double outer_radius, double inner_radius) {
  return (M_PI * outer_radius * outer_radius) - (M_PI * inner_radius * inner_radius);
  return 0;
}

int bigger_minus_smaller(int a, int b) {
  if(a > b)
  {
    return a - b;
  }
  else
  {
    return b - a;
  }
  return 0;
}

bool value_in_range(int lower_bound, int x, int upper_bound) {
  if(x >= lower_bound && x <= upper_bound)
  {
    return true;
  }
  return false;
}
