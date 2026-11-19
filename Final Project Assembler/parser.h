// Hold global definitions for use in the project

#ifndef PARSER_H
#define PARSER_H

#include <stdint.h>

#define MAX_LBL_LEN 10  // Longest name length a label can have

typedef enum {
    MODE_IMM,   // immediate            #$00
    MODE_ZP,    // zero page            $00
    MODE_ZPX,   // zero page x          $00,X
    MODE_ZPY,   // zero page y          $00,Y
    MODE_ABS,   // absolute             $0000
    MODE_ABSX,  // absolute x           $0000,X
    MODE_ABSY,  // absolute y           $0000,Y
    MODE_IND,   // indirect             ($0000)
    MODE_PXIND, // pre-inc indirect x   ($0000,x)   Worse DirectX?? Michaelsoft Binboes?
    MODE_PYIND, // post-inc indirect y  ($0000,y)
    MODE_IMP,   // no operand
} address_mode;

typedef struct {
    char mnemonic[4];
    address_mode mode;
    uint8_t opcode;
    int line_number;
} instruction;

// struct directive {
//     char operation[9]; // preemptively making this large enough to hold .include
//                        // in case I ever add that functionality
//     char *parameters;
// };

instruction inst_table[] {
   instruction{.mnemonic = "LDA", .mode = MODE_IMM, .opcode = 0xA9}, // example
   instruction{.mnemonic = "LDA", .mode = MODE_IMM, .opcode = 0xA9},
   instruction{.mnemonic = "LDA", .mode = MODE_IMM, .opcode = 0xA9},
   instruction{.mnemonic = "LDA", .mode = MODE_IMM, .opcode = 0xA9},
   instruction{.mnemonic = "LDA", .mode = MODE_IMM, .opcode = 0xA9},
   instruction{.mnemonic = "LDA", .mode = MODE_IMM, .opcode = 0xA9},
   instruction{.mnemonic = "LDA", .mode = MODE_IMM, .opcode = 0xA9},
   instruction{.mnemonic = "LDA", .mode = MODE_IMM, .opcode = 0xA9},
   instruction{.mnemonic = "LDA", .mode = MODE_IMM, .opcode = 0xA9},
   instruction{.mnemonic = "LDA", .mode = MODE_IMM, .opcode = 0xA9},
   instruction{.mnemonic = "LDA", .mode = MODE_IMM, .opcode = 0xA9},
}

#endif
