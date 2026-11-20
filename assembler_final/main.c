/***************************************
 * 6502 Assembler Main
 **************************************/

#include <stdio.h>
#include <stdlib.h>
#include "parser.h"


int main(int argc, char *argv[]) {
    FILE *src;  // source .asm file
    FILE *dest; // destination .bin

    long start_file;
    long file_size;

    if (argc == 1) {
        printf("%s: missing file.\n", argv[0]);
    }

    src = fopen(argv[1], "r");
    if (src == NULL) {
        printf("Could not locate \"%s\"\n", argv[1]);
        exit(EXIT_FAILURE);

    }

    fseek(src, 0L, SEEK_END);
    file_size = ftell();



    return 0;
}
