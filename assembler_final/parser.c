// Common functions

#include "parser.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>

const instruction inst_table[] = {
    {.mnemonic = "LDA", .mode = MODE_IMM,  .opcode = 0xA9},
    {.mnemonic = "LDA", .mode = MODE_ZP,   .opcode = 0xA5},
    {.mnemonic = "LDA", .mode = MODE_ZPX,  .opcode = 0xB5},
    {.mnemonic = "LDA", .mode = MODE_ABS,  .opcode = 0xAD},
    {.mnemonic = "LDA", .mode = MODE_ABSX, .opcode = 0XBD},
    {.mnemonic = "LDA", .mode = MODE_ABSY, .opcode = 0XB9},
    {.mnemonic = "LDA", .mode = MODE_INDX, .opcode = 0xA1},
    {.mnemonic = "LDA", .mode = MODE_IMM,  .opcode = 0xA9},

// Further values are placeholders until modified for more instructions
//    instruction{.mnemonic = "LDA", .mode = MODE_IMM, .opcode = 0xA9},
//    instruction{.mnemonic = "LDA", .mode = MODE_IMM, .opcode = 0xA9},
//    instruction{.mnemonic = "LDA", .mode = MODE_IMM, .opcode = 0xA9},
};

char *find(const char *cursor, find_type mode) {
    char *location = cursor;

    switch (mode) {
        case LINE: {
            while(1) {
                if (*location == '\n') {return location + 1;}
                if (*location == EOF)  {return NULL;}
                ++location;
            }
        }

        case NEXT_STATE: {
            while(1) {
                if (*location == EOF) {return NULL;} // Catch EOF before its returned
                if (isalpha(location) || !strchr(*location, " \t")) {return location;}
                ++location;
            }
        }
    }
}


