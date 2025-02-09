#include "midterm.h"

#include <stdio.h>
#include<math.h>

int num_with_highest_square(int a, int b, int c) {
  int asquare = a * a;
  int bsquare = b * b;
  int csquare = c * c;

  if(asquare > bsquare && asquare > csquare)
    return a;
  else if(bsquare > asquare && bsquare > csquare)
    return b;
  else if(csquare > bsquare && csquare > asquare)
    return c;
  return 0;
}
