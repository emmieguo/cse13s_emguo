#include "final.h"

#include <stdio.h>

char **alphabet_sequences(int maxsize) {
  // Your code here!
  // remember, you're going to need to allocate the array of strings you're
  // returning. and you'll also need to allocate each string in that array.
  char **sequences = calloc(maxsize, sizeof(char*));
  for(int i = 0; i < maxsize; i++){
    sequences[i] = calloc(i + 2, sizeof(char));
    for(int j = 0; j <= i; j++){
      sequences[i][j] = 'a' + j%26;
    }
  }
  return sequences;
}
