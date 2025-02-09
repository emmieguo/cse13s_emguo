#include "midterm.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *a, char *b) { 
  char temp = *a; 
  *a = *b; 
  *b = temp; 
}  

char *alphabetize_word(char *word) {
  char* newword = strdup(word);
  int n = strlen(word);
  for (int i = 0; i < n - 1; i++){
    for (int j = 0; j < n - i - 1; j++){
      char a = newword[j];
      char b = newword[j+1];
      if(strcmp(&a, &b) > 0){
        swap(&newword[j], &newword[j+1]);
      }
    }
  }
  return newword;
}

