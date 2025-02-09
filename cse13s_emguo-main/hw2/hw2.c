/*
 * All of your code goes in here. You need to finish these functions.
 */

#include "hw2.h"

int next_collatz_number(int n) {
  if(n % 2 == 0){
    return(n / 2);
  }
  else if(n % 2 == 1){
    return(3 * n + 1);
  }
  return 0;
}

int count_collatz_steps(int n) {
  int count = 0;
  if(n == 1){
    return count;
  }
  while(n != 1){
    n = next_collatz_number(n);
    count++;
  }
  return count;
}

int maximum(int *nums, int len) {
  int largest = nums[0];
  int a = 1;
  while(len != 0){
    if(nums[a] > largest){
      largest = nums[a];
    }
    len = len - 1;
    a++;
  }
  return largest;
}

int sum_positive(int *nums, int len) {
  int sum = 0;
  int a = 0;
  while(len != 0){
    if(nums[a] > 0){
      sum = sum + nums[a];
    }
    a++;
    len = len - 1;
  }
  return sum;
}

int count_negative(int *nums, int len) {
  int count = 0;
  int a = 0;
  while(len != 0){
    if(nums[a] < 0){
      count++;
    }
    len = len - 1;
    a++;
  }
  return count;
}
