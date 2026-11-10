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
#include <time.h>

#define END_MARK '\032'

enum terminate_flag { NO_TERM, TERM };

char *find_next_word(char *ch, bool terminate);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename.txt>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *fp;
    long count, last;

    // Find length of file (last)
    fopen(argv[1], "br");
    fseek(fp, 0L, SEEK_END);
    last = ftell(fp);
    rewind(fp);

    // Create buffer to store whole file
    int num_chars = last * sizeof(char);
    char *working_file = malloc(num_chars + 1);
    fread(working_file, sizeof(char), last, fp);
    working_file[num_chars] = '\0';

    // Scan through file and count total number of individual words
    int word_count = 0;
    char *idx = &working_file[0];
    while(!isalpha(idx++)){} // Skip over non-letters at the start if present.
    working_file = idx;
    while(*idx != '\n') {
        idx = find_next_word(idx, NO_TERM);
        ++word_count;
    }

    char *word_list[word_count];



    return(0);
}

char *find_next_word(char *ch, bool terminate) {
    while(isalpha(++ch) && *ch != '\0') {}

    if (terminate) {
        *ch = '\0';
    }

    while(!isalpha(++ch) && *ch != '\0') {}
    return(ch);
}

