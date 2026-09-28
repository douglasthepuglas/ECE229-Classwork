#include <stdio.h>
#include <string.h>

// given a char array buffer, ask the user to input a sentence
// the sentence will be a string in the buffer
// return the string length
int get_sentence(char str[], int max) {
  
  int n = 0;
  
#ifdef DEBUG
  printf("get_sentence(str=\"%s\",max=%d) called\n",str,max);
#endif

  // get input sentence
  printf("Enter a sentence, press enter when done...\n");
  do {
    str[n] = getchar(); // read one char at a time
    ++n;
  } while (str[n - 1] != '\n' &&
           n < max); // until the user enters \n or max chars is reached

  str[n - 1] = '\0'; // replace last \n with a null trerminator so we can use
                     // snetence as a string.

  return n - 1; // strlen
}

// reverses a string in place
void reverse_string(char str[]) {
#ifdef DEBUG
  printf("reverse_string(str=\"%s\") called\n",str);
#endif

  int start = 0;             // start of the string
  int end = strlen(str) - 1; // last char in the string.

  while (
      start <
      end) { // swap chars until start and end meet at the center of the string.
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    ++start; // increments the start pointer moving it one char forward.
    --end;   // decrements the end pointer moving it one char backward.
  }
}