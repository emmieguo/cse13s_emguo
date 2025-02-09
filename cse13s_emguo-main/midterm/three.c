#include "midterm.h"

#include <stdio.h>
#include <stdlib.h>

LLint *push(LLint *list, int val) {
  LLint *out = (LLint *)calloc(1, sizeof(LLint));
  out->next = list;
  out->val = val;
  return out;
}

int reduce(LLint *nums, int (*f)(int, int), int initial) {
  if(nums == NULL)
    return initial;
  initial = f(initial, nums->val);
  return reduce(nums->next, f, initial);
}
