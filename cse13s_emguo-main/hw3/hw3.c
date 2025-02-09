/*
 * All of your code goes in here. You need to finish these functions.
 */

#include "hw3.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

bool str_suffix(char *haystack, char *needle) {
  if(strcmp(haystack + (strlen(haystack) - strlen(needle)), needle) == 0)
    return true;
  return false;
}

float dot_product(float *vec_a, float *vec_b, int length) {
  float dot = 0.0;
  int current = 0;
  while(length != 0){
    dot = dot + vec_a[current] * vec_b[current];
    current++;
    length = length - 1;
  }
  return dot;
}

int reduce(int *nums, int length, int (*f)(int,int), int initial) {
  for(int i = 0; i < length; i++)
    initial = f(initial, nums[i]);
  return(initial);
}


// These two functions will end up as a *single call to reduce*, but you'll have
// to write a new helper function for each of them. Those helper functions will
// be quite short though!

int max(int x, int y){
  if(x > y)
    return x;
  return y;
}

int maximum_with_reduce(int *nums, int length) {
  return reduce(nums, length, max, nums[0]);
}

int sum_pos(int return_val, int x){
  if(x > 0)
    return_val += x;
  return return_val;
}

int sum_positive_with_reduce(int *nums, int length) {
  return reduce(nums, length, sum_pos, 0);
}
