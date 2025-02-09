#include "review.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Functions for you to implement. Most of the work for this homework will be
// done in here, but you'll also need to make changes to review.h and yelling.c.

// Problem 1
void sum_and_difference(int a, int b, int *sum, int *difference) {
  *sum = a + b;
  *difference = a - b;
}

// Problem 2

// This one ought to be recursive.
size_t ll_length(LLint *node) {
  //  TODO(you): your code here
  if(node == NULL)
    return 0;
  return 1 + ll_length(node->next);

}

// Do this one iteratively.
size_t ll_length_iterative(LLint *node) {
  size_t length = 0;
    while(node != NULL){
      node = node->next;
      length++;
    }
  return length;
}

// Problem 3.
LLdouble *stack_push(LLdouble *node, double item) { 
  LLdouble *new = (LLdouble *)calloc(1, sizeof(LLdouble));
  new->val = item;
  new->next = node;
  return new;
}

void stack_pop(LLdouble **node, double *ret) {
  if (!(*node) || !node){
    return;
  }
  *ret = (*node)->val;
  LLdouble *freethis = *node;
  *node = (*node)->next;
  free(freethis);
}

void reverse_doubles_with_stack(double *array, size_t array_len) {
  // This function will reverse the order of the array pointed to by *array.
  // Make sure to define your linked list data structure in review.h, and use
  // stack behavior (LIFO) to get the numbers in the reversed order.
  // There is a way to do this without a stack data structure, I know. But this
  // is for practice with data structures.
  //
  //  TODO(you): your code here
  LLdouble *stack = (LLdouble *)calloc(1, sizeof(LLdouble));
  for(size_t i = 0; i < array_len; i++){
    stack = stack_push(stack, array[i]);
  }
  double output;
  for(size_t i = 0; i < array_len; i++){
    stack_pop(&stack, &output);
    array[i] = output;
  }
}

// Problem 4.

tnode *word_observe(char *word, tnode *node) {
  // This function returns a pointer to a tnode because you may have to allocate
  // a new one. You might take a NULL pointer to start with.
  // Also, this means that you can very cleanly do this with recursion.
  //strcmp < 0 --> left
  //strcmp > 0 --> right
  //strcmp = 0 add 1 to count
  if(node == NULL){
    node = (tnode *)calloc(1, sizeof(tnode));
    node->word = strdup(word);
    node->count = 1;
    return node;
  }
  
  int mommy = strcmp(word, node->word);
  if(mommy < 0){
    node->left = word_observe(word, node->left);
  }
  if(mommy > 0){
    node->right = word_observe(word, node->right);
  }
  if(mommy == 0){
    node->count++;
  }
  return node;
}

int word_count(char *word, tnode *node) {
  // Default return values; here for you to change.
  if(node == NULL){
    return 0;
  }
  if(strcmp(word, node->word) > 0){
    return word_count(word, node->right);
  }
  if(strcmp(word, node->word) < 0){
    return word_count(word, node->left);
  }
  return node->count;
}

void delete_tree(tnode *node) {
  // Free the whole tree and all associated memory. This can be recursive or
  // not, your choice!
  if(node){
    delete_tree(node->left);
    delete_tree(node->right);
    free(node->word);
    free(node);
  }
}