#include "final.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

size_t word_count(char *text) {
  // Your code here!
  // Count up all the words that occur in the given string. A new word starts
  // when you see a letter a-z or A-Z.
  if(strcmp(text, "") == 0){
    return 0;
  }

  size_t count = 0;

  for(int i = 0; i < strlen(text); i++){
    if(isalpha(text[i]) && !isalpha(text[i+1])){
      count++;
    }
  }
  return count;
}