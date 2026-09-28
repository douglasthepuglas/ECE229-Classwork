/**************************************************
 * Author:      Bill Westrick
 * Lab:         Lecture 09 example
 * Description: Uses arrays to reverse
 *              an input string multi-file version
 * ***********************************************/

#include "utils.h"
#include <stdbool.h>
#include <stdio.h>

int main(void) {

  char sentence[BUFFER_SIZE]; // buffer to hold sentence
  int index;

  get_sentence(sentence, BUFFER_SIZE);

  printf("Your sentence in reverse:\n");
  reverse_string(sentence);
  printf("%s\n", sentence);

  printf("\nBye.\n");

  return 0;
}
