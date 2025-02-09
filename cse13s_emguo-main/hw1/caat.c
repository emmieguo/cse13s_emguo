#include <stdio.h>

int main(void) {
  // Finish this program. You'll almost certainly want to use a loop of some
  // kind, getchar() and putchar(). Remember that the output of getchar() is the
  // symbol EOF when you get to the end of the input.
  int c;
    while((c = getchar()) != EOF)
    {
      switch(c){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        {
          putchar(c);
        }
      }
      putchar(c);
        
    }

  return 0;
}
