# Homework 7 Design Doc

# score_letter
This function should return the number of words that contain a certain character in the array of array vocabulary. 
To check for this, we should loop over all of the elements in vocabulary and check to see if we have seen this before, if not, we check to see if it has the letter and add one to the return val if it does.

    int score_letter(char letter, char **vocabulary, size_t num_words) {
        total = 0;
        for(size_t i = 0; i < num_words; i++){
            if(strchr(vocabulary[i], letter) != NULL)
                total++;
        }
        return total;
}

# score_word
This function should calculate a score for a given word where our "score board" is a 2D array which is length 26 and contains the individual scores that are linked with the specific position in the alphabet. a --> 0, b --> 1, c --> 2, ..., z --> 25. To do this, we should loop through the word we are scoring and index letter scores to get the score we want and append that to the final score to be returned. How to index letter scores is a hint given by the fact that the ASCII for 'a' is 97, 'b' is 98, 'c' is 99 and so on.

    /* So, if we have the letter c in our word, the score of c is at index 2 of the scores array and c is ASCII 99. Then how do we get 2 from 99? We can use the base ASCII for 5 which is 97. So 99-97 is 2!
    */

    int score_word(char *word, int *letter_scores) {
        total = 0;
            for(int i = 0; i < 5; i++){
                total += letter_scores[word[i] - 'a'];
            }
        return total;
    }

# filter_vocabulary_gray
This function should free all elements of vocaulary that contain the letter because we want to filter the ones that are grey. In order to do this, we have to check; if the letter is in the word, we free it. Do this through a loop.

    size_t filter_vocabulary_gray(char letter, char **vocabulary, size_t num_words) {
        total = 0;
        for(size_t i = 0; i < num_words; i++){
            if(strchr(vocabulary[i], letter) != NULL){
                free(vocabulary[i]);
                    total++;
            }
        }
        return total;
    }

# filter_vocabulary_yellow
This function should free all elements of the vocabulary that either do not contian the letter in the word or contains the letter at the specified spot. This will filter for the yellows. 

    size_t filter_vocabulary_yellow(char letter, int position, char **vocabulary, size_t num_words) {
        total = 0;
        for(size_t i = 0; i < num_words; i++){
            if((strchr(vocabulary[i], letter) == NULL) || (vocabulary[i][position] == letter)){
                free(vocabulary[i]);
                total++;
            }
        }
        return total;
    }

# filter_vocabulary_green
This function filters out all of the green, so it will free elements in vocabulary that do not have the letter at the specified position in the word.

    size_t filter_vocabulary_green(char letter, int position, char **vocabulary, size_t num_words) {
        total = 0;
        for(size_t i = 0; i < num_words; i++){
            if(vocabulary[i][position] != letter){
                free(vocabulary[i]);
                total++;
            }
        }
        return total;
    }
