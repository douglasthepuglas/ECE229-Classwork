/***************************************
 * 6502 Assembler Main
 **************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "parser.h"

int main(int argc, char *argv[]) {
    FILE *src;  // source .asm file
    //FILE *dest; // destination .bin

    // Pointer to program start declared later as const; MUST HOLD ONTO THIS
    long     file_size;
    char     buffer[MAX_COM_LEN];
    int      line_number = 1;
    uint16_t program_counter;

    // Symbol and label tables (e.g. PORTB = $00 or LOOP: respectively)
    // These max values will increment & realloc if table fills.
    int     symbols_max  = 50; 
    int     labels_max   = 50;
    symbol *symbol_table = malloc(symbols_max * sizeof(symbol));
    label  *label_table  = malloc(labels_max * sizeof(label));
    int     num_symbols  = 0; // keep track of numbers of each to know when full
    int     num_labels   = 0;

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

    char *cursor = malloc(file_size * sizeof(char) + 1); // File buffer. yay
    if (cursor == NULL) {
        printf("Error: Could not allocate memory.\n");
        exit(EXIT_FAILURE);
    }

    #ifdef DEBUG
    for (int i = 0; i < file_size; ++i) {
        printf("%c", program[i]);
    }
    #endif

    fread(cursor, sizeof(char), file_size, src);
    fclose(src);

    const char *program = cursor; // Create permanent reference to prog start

    // Print a few test chars to see if functions work
    #ifdef DEBUG
    printf("%c\n", *cursor);
    cursor = find(cursor, LINE);
    printf("%c\n", *cursor);
    #endif

    // Current State: Cursor is now at the start of the file
    //
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

    // Finally, the main loop
    //while (1) {
        // This is done before the line is stripped
        instruction_type type_flag;
        if (isalpha(*cursor)) {
            cursor = extract_string(cursor, buffer);
            if (*cursor == ':') {
                type_flag = LABEL;
                int char_overflow = snprintf(label_table[num_labels].name, //...
                                    sizeof(MAX_COM_LEN), "%s", buffer);
                if (char_overflow != 0) {
                    //error
                }
                label_table[num_labels].location = program_counter;
                ++program_counter;
                ++num_labels;
            }
        }
        
        #ifdef DEBUG
        printf("%c\n", *cursor);
        #endif 

        if (isalpha(*cursor)) {
            cursor = extract_string(cursor, buffer);
        }

        printf("\"%s\", \"%c\"\n", buffer, *cursor);

        // Need to 

        ++line_number;
    //}
    
    return 0;
}


//sss