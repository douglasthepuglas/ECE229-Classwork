/**************************************************
 * Author:      Douglas Cannizzaro
 * Lab:         Lab 10, project 1
 * Description: Finds smallest and largest word entered until user enters a four
 *              letter word, then print the largest and smallest word.
 ************************************************/

#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LENGTH 20

int main(void) {
    char word_buffer[MAX_WORDS][MAX_LENGTH + 1];
    int word_index = 0;

    char *smallest_word   = &word_buffer[word_index][0];
    int len_smallest_word = MAX_LENGTH;

    char *largest_word    = &word_buffer[word_index][0];
    int len_largest_word  = 0;

    while(1) {
        printf("Enter word: ");
        scanf("%s", &word_buffer[word_index][0]);

        int current_length = strlen(&word_buffer[word_index][0]);

        if (current_length > len_largest_word) {
            largest_word = &word_buffer[word_index][0];
            len_largest_word = current_length;
        }

        if (current_length < len_smallest_word) {
            smallest_word = &word_buffer[word_index][0];
            len_smallest_word = current_length;
        }

        if (current_length == 4) {
            break;
        }

        ++word_index;
    }

    printf("\nSmallest word: %s\n", smallest_word);
    printf("Largest word : %s\n", largest_word);


    return(0);
}
