#include "final.h"

#include <stdio.h>

int count_values_at_least(int value, BinaryTree *tree) {
  // Your code here!
  // Remember, this is just a regular binary tree, not a binary *search* tree.
  if(tree == NULL)
    return 0;
  if(value <= tree->val)
    return 1 + count_values_at_least(value, tree->right) + count_values_at_least(value, tree->left);
  else
    return count_values_at_least(value, tree->right) + count_values_at_least(value, tree->left);
}
