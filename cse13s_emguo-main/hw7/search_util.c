#include "search_util.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


// This function should loop over the vocabulary (which contains num_words
// entries) and return the number of words in which that particular letter
// occurs. So if there are 15 words containing the letter 'x' for the particular
// vocabulary, then this function will return 15.
int score_letter(char letter, char **vocabulary, size_t num_words) {
  int num = 0;
  for(size_t i = 0; i < num_words; i++){
    if(vocabulary[i]){
      num = num + (strchr(vocabulary[i], letter) != NULL);
    }
  }
  return num;
}


// Calculate the score for a given word, where the letter_scores array has
// already been filled out for you and is guaranteed to be of length 26. Slot 0
// contains the score for 'a', and slot 25 contains the score for 'z'.
// The score for a word is the sum of all of the letter scores, *for unique
// letters*. So if the letter 'e' occurs three times, it only contributes to the
// score once.
int score_word(char *word, int *letter_scores) {

  // TODO(you): implement this function!
  int score = 0;
  char visited[6] = "";
  int spot = 0;
  for(int i = 0; i < 5; i++){
    if(!strchr(visited, word[i])){
      score += letter_scores[word[i] - 'a'];
      visited[spot] = word[i];
      spot++;
    }
  }
  return score;

}

// Returns the optimum guess, based on our heuristic.
// This one works, you don't have to change it.
// Note that this function allocates a new string every time it runs, and those
// strings will need to be freed!
char *get_guess(char **vocabulary, size_t num_words) {
  int letter_scores[26];

  for (int i = 0; i < 26; i++) {
    letter_scores[i] = score_letter('a' + i, vocabulary, num_words);
  }

  char *best_guess = NULL;
  int best_score = 0;
  int score = 0;
  for (size_t i = 0; i < num_words; i++) {
    if (vocabulary[i] == NULL) {
      continue;
    }
    score = score_word(vocabulary[i], letter_scores);
    if (score > best_score) {
      best_guess = vocabulary[i];
      best_score = score;
    }
  }
  return best_guess ? strdup(best_guess) : NULL;
}

// This function will filter down the vocabulary based on the knowledge that the
// specified letter *does not occur* in the secret word. So for any of the words
// in the vocabulary that do contain that letter, free their pointers and set
// the corresponding slot to NULL.
// Returns the number of words that have been filtered from the vocabulary.
size_t filter_vocabulary_gray(char letter, char **vocabulary, size_t num_words) {

  // TODO(you): implement this function!

  size_t total = 0;
  for(size_t i = 0; i < num_words; i++){
    if(vocabulary[i]){
      if(strchr(vocabulary[i], letter) != NULL){
        free(vocabulary[i]);
        vocabulary[i] = NULL;
        total++;
      }
    }
  }
  return total;
}

// This function will filter down the vocabulary based on the knowledge that the
// specified letter occurs in the word, *but not at this particular position*.
// So remove any words that either don't contain the letter at all, or do
// contain it, but at the specified position.
// Returns the number of words that have been filtered from the vocabulary.
size_t filter_vocabulary_yellow(char letter, int position, char **vocabulary, size_t num_words) {

  // TODO(you): implement this function!

  size_t total = 0;
  for(size_t i = 0; i < num_words; i++){
    if(vocabulary[i]){
      if((strchr(vocabulary[i], letter) == NULL) || (vocabulary[i][position] == letter)){
        // this only checks for the first instance and not the position
        free(vocabulary[i]);
        vocabulary[i] = NULL;
        total++;
      }
    }
  }
  return total;
}


// This function will filter down the vocabulary based on the knowledge that the
// specified letter *definitely* occurs as the specified position. So remove any
// word that does not contain, for the specified position, the specified letter.
// Returns the number of words that have been filtered from the vocabulary.
size_t filter_vocabulary_green(char letter, int position, char **vocabulary, size_t num_words) {

  // TODO(you): implement this function!

  size_t total = 0;
  for(size_t i = 0; i < num_words; i++){
    if(vocabulary[i]){
      if(vocabulary[i][position] != letter){
        free(vocabulary[i]);
        vocabulary[i] = NULL;
        total++;
      }
    }
  }
  return total;

}

// Free each of the strings in the vocabulary, as well as the pointer vocabulary
// itself (which points to an array of char *).
void free_vocabulary(char **vocabulary, size_t num_words) {
  for (size_t i = 0; i < num_words; i++) {
    free(vocabulary[i]);
  }
  free(vocabulary);
}
