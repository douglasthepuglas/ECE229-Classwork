/**************************************************
 * Author:      Douglas Cannizzaro
 * Lab:         Lab , project
 * Description:
 ************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

enum terminate_flag { NO_TERMINATE, TERMINATE };

// Functions
char *find_next_word(char *ch, bool terminate);
int compare_words(const void *a, const void *b);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename.txt>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *fp;
    long count, last;
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening \"%s\".\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Find length of file (last)
    fseek(fp, 0L, SEEK_END);
    last = ftell(fp);
    if (last == 0) {
        printf("\'%s\' is empty. Please supply a file with words.\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    rewind(fp);

    // Create memory block for the whole file
    int num_chars = last * sizeof(char);
    char *working_file_buffer = malloc(num_chars + 1);
    fread(working_file_buffer, sizeof(char), last, fp);
    working_file_buffer[num_chars] = '\0';

    // Define new "working file" start pointer at first alpha char.
    // Old pointer must be kept to be freed later.
    char *idx = &working_file_buffer[0];
    while(!isalpha(*idx)){
        if (*idx == '\0') {
            printf("\"%s\" contains no words.\n", argv[1]);
            free(working_file_buffer);
            exit(EXIT_FAILURE);
        }
        ++idx;
    }

    char *working_file = idx; // New start

    // Count words to determine max buffer size for number of word pointers
    int word_count = 0;
    while(*idx != '\0') {
        idx = find_next_word(idx, NO_TERMINATE);
        ++word_count;
    }
    int indiv_counts[word_count]; // guaranteed to have one word
    for (int i = 0; i < word_count; ++i) {
        indiv_counts[i] = 0;
    }

    // Write all word pointers
    idx = &working_file[0];
    char *word_list[word_count];
    for (int i = 0; i < word_count; ++i) {
        word_list[i] = idx;
        idx = find_next_word(idx, TERMINATE);
    }

    qsort(word_list, word_count, sizeof(char*), &compare_words);

    // count total unique words while changing the first entries of word_list
    // into the unique words in order
    int unique_words = 1; // store as literal number, index from one before.
    for (int i = 0; i < word_count; ++i) {
        if (strcmp(word_list[i], word_list[unique_words - 1])) {
            ++unique_words;
            word_list[unique_words - 1] = word_list[i];
        }
        ++indiv_counts[unique_words - 1];
    }

    // Print all info
    printf("Total word count: %d\n", word_count);
    printf("Individual word counts:\n");
    for (int i = 0; i < unique_words; ++i) {
        printf("%s: %d\n", word_list[i], indiv_counts[i]);
    }
    free(working_file_buffer);
    return(0);
}

char *find_next_word(char *ch, bool terminate) {
    *ch = tolower(*ch);
    while(isalpha(*(ch))) { // safe to increment first because ch will be a
        *ch = tolower(*ch);
        ++ch;
    }

    if (terminate) {
        if (*ch == '\0') {
            return(ch);
        }
        *ch = '\0';
        ++ch;
    }

    while(*ch != '\0' && !isalpha(*(ch))) {
        ++ch;
    }

    return(ch);
}

int compare_words(const void *a, const void *b) {
    const char *word_a = *(const char**)a;
    const char *word_b = *(const char**)b;
    return strcmp(word_a, word_b);
}
