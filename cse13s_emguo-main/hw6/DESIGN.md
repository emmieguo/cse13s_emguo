# Homework 6 Design Doc

# score_guess
The point of wordle is to guess a five letter word. 
If the word is guessed correctly, return true. Else, false.
Compare letter by letter:

    Gray/x if the letter is not in the word.
    Yellow/y if the letter is in the word but in the incorrect spot
    Green/g if the letter is in the correct spot

Then, write the output of each comparison to result. (No need for memory allocation)
Return true if secret == guess.

    bool score_guess(char *secret, char *guess, char *result) {
        int num_correct = 0;
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                if(strcmp(secret[i], guess[i]) == 0){
                    result[i] = "g";
                    num_correct++;
                }
                else if(strcmp(secret[j]), guess[i] == 0){
                    result[i] = "y";
                }
                else{
                    result[i] = "x";
                }
            }
        }
        if(num_correct == 5)
            return true;
        return false;
    }



# valid_guess
This function returns true if the guess string is in the vocabulary.
To do this, we compare one to one. Remember to compare the actual values and not the pointers.
To do this, use strcmp or strncmp.
We can do a for loop but this can be inefficient. Instead we can do a binary search. BUT you can still use linear search.

    bool valid_guess(char *guess, char **vocabulary, size_t num_words) {
        // TODO(you): finish this function
        // *vocabulary is the string word, must dereference it
        int correct = 0;
        for(int i = 0; i < num_words; i++){
            char *curr = *vocabulary[i];
            for(int j = 0; j < 5; j++){
                if(strcmp(guess[i], curr[i]) == 0){
                    correct++;
                }
            }
            if(correct == 5)
                return true;
        }
        return false;
    }


# **load_vocabulary
For this function, we need to open file --> read lines --> use fgets --> close file
We want to return an array of strings. Use realloc in this function because the array is dynamically growing
    void *realloc(void *ptr, size_t size);
Use fopen to open the input file for reading,
strdup (or strndup) to make copies of each word read from that file, and
fclose to close the file when you are done reading from it.
Each element of the array should be a single five-letter word,
BUT, realloc can lead to leaks because the old memory has not been freed.

    // demo for realloc
    char **vocab = (char**)calloc(5,sizeof(char*));
    char **new_vocab = realloc(vocab, 7 * sizeof(char*));
    if(new_vocab){
        vocab = new_vocab;
    }
What is strdup/strndup? --> this copies a string. Remember to free the strings that these two functions return when you finish whith them. This will prevent leaks. These are allocated on the stack.

# free_vocabulary
This function is mean to free all of the memory that was used in vocabulary, as well as the pointer vocabulary

    void free_vocabulary(char **vocabulary, size_t num_words) {
        for (int i = 0; i < num_words; i++) {
            free((*vocabulary[i];
        }
        free(*vocabulary);
        }
    }
