/***************************************
 * 6502 Assembler Main
 **************************************/

#include <stdio.h>
#include <stdlib.h>
#include "parser.h"


int main(int argc, char *argv[]) {
    FILE *src;  // source .asm file
    FILE *dest; // destination .bin

    // Pointer to source file declared later as const; MUST HOLD ONTO THIS
    char *cursor = NULL; // Re-initialized later as "program" before each pass
    long file_size;

    // Error?
    if (argc == 1) {
        printf("%s: missing file.\n", argv[0]);
    }

    src = fopen(argv[1], "r");
    if (src == NULL) {
        printf("Could not locate \"%s\"\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // NO FILE OPERATIONS IN MY CODE! I HATE THEM, so into buffer the file goes.
    fseek(src, 0L, SEEK_END);
    file_size = ftell(src);
    rewind(src);

    const char *program = malloc(file_size * sizeof(char) + 1); // Buffer. yay
    if (program == NULL) {
        printf("Error: Could not allocate memory.\n");
        exit(EXIT_FAILURE);
    }

    #ifdef DEBUG
    for (int i = 0; i < file_size; ++i) {
        printf("%c", program[i]);
    }
    #endif

    fread(program, sizeof(char), file_size, src);
    fclose(src);

    #ifdef DEBUG
    cursor = program;   // Took me a while to find that cursor wasn't initialized.
    printf("%c\n", *cursor);
    cursor = find(cursor, LINE);

    printf("%c\n", *cursor);
    #endif

    // Check what type of line the assembler is about to parse.
    // *the following lines assume no error, but that'll be addressed
    //      -If the first character of a line is whitespace, must be instruction
    //        or . directive
    //      -If first char is alpha, line must be either a label or symbol
    //          -Therefore, load remaining chars in string into buffer until
    //           one of two cases:
    //              1. Whitespace OR =: skip whitespace until =, store following
    //                 value and string in symbol table.
    //              2. (:): store following string until whitespace or \n in
    //                 label table
    // Check for errors at intersection points between checking for different
    // char types
    //

    return 0;
}
//sss