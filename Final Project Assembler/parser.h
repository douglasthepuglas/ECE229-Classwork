// Hold global definitions for use in the project

#ifndef PARSER_H
#define PARSER_H

#include <stdint.h>

#define MAX_COM_LEN 10  // Common longest length a label, definition, or
                        // assembler directive name string can have

// Address modes used across all instructions
// $00 and $0000 used purely as placeholder examples.
typedef enum {
    MODE_IMM,   // immediate            #$00
    MODE_ZP,    // zero page            $00
    MODE_ZPX,   // zero page x          $00,X
    MODE_ZPY,   // zero page y          $00,Y
    MODE_ABS,   // absolute             $0000
    MODE_ABSX,  // absolute x           $0000,X
    MODE_ABSY,  // absolute y           $0000,Y
    MODE_IND,   // indirect             ($0000)
    MODE_INDX,  // pre-inc indirect x   ($0000,x)   Worse DirectX?? Michaelsoft Binboes?
    MODE_INDY,  // post-inc indirect y  ($0000,y)
    MODE_IMP,   // no operand
} address_mode;

// Container for individual instructions
typedef struct {
    char mnemonic[4];
    address_mode mode;
    uint8_t opcode;
    int line_number; /* Immutable instruction table leaves this blank;
                        individual tokens will copy template and add line num */
} instruction;

// User definitions (e.g. PORTB = $6000)
typedef struct {
    char name[MAX_COM_LEN];
    uint16_t value;
} definition;

// Labels
typedef struct {
    char name[MAX_COM_LEN];
    uint16_t location;
} label;

// Union for pointer type directive.
// Void because directives take string or value args
typedef void * directive_arg;


// Assembler directives. Will be supported later.
typedef struct {
    char direc_name[MAX_COM_LEN];
    directive_arg parameter_table;
    int line_number; /* Same case as instruction table */
} directive;

const instruction inst_table[] {
   instruction{.mnemonic = "LDA", .mode = MODE_IMM,  .opcode = 0xA9},
   instruction{.mnemonic = "LDA", .mode = MODE_ZP,   .opcode = 0xA5},
   instruction{.mnemonic = "LDA", .mode = MODE_ZPX,  .opcode = 0xB5},
   instruction{.mnemonic = "LDA", .mode = MODE_ABS,  .opcode = 0xAD},
   instruction{.mnemonic = "LDA", .mode = MODE_ABSX, .opcode = 0XBD},
   instruction{.mnemonic = "LDA", .mode = MODE_ABSY, .opcode = 0XB9},
   instruction{.mnemonic = "LDA", .mode = MODE_INDX, .opcode = 0xA1},
   instruction{.mnemonic = "LDA", .mode = MODE_IMM,  .opcode = 0xA9},

   // Further values are placeholders until modified for more instructions
//    instruction{.mnemonic = "LDA", .mode = MODE_IMM, .opcode = 0xA9},
//    instruction{.mnemonic = "LDA", .mode = MODE_IMM, .opcode = 0xA9},
//    instruction{.mnemonic = "LDA", .mode = MODE_IMM, .opcode = 0xA9},
};

// Bring all of them into a union so functions can output any
typedef union {
    instruction;

}
// lineread();


#endif