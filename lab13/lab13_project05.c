/**************************************************
 * Author:      Douglas Cannizzaro
 * Lab:         Lab 13, project 5
 * Description: Prompt user to input strings until the input is only "\n".
 *              Sort these words alphabetically.
 ************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define __STDC_WANT_LIB_EXT2__ 1
#define MAX_WORD_LENGTH 20
#define MAX_NUM_WORDS 100

int compare_strings(const void *a, const void *b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

int main(void) {
    char *str_pointers[MAX_NUM_WORDS];
    char buffer_string[MAX_WORD_LENGTH + 1];
    int current_index = 0;

    do {
        printf("Enter word: ");
        fgets(buffer_string, sizeof(buffer_string), stdin);

        str_pointers[current_index] = strdup(buffer_string);

        ++current_index;

    } while (*buffer_string != '\n');

    qsort(str_pointers, current_index - 1, sizeof(char*), compare_strings);

    printf("Sorted: ");
    for (int i = 0; i < current_index - 1; ++i) {
        *strchr(str_pointers[i], '\n') = 0;
        printf("%s ", str_pointers[i]);
    }

    printf("\n");

    return(0);
}
