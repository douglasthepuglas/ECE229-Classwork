// Hold global definitions for use in the project

#ifndef PARSER_H
#define PARSER_H

#include <stdint.h>

#define MAX_LBL_LEN 10  // Longest name length a label can have

typedef enum {
    NONE,
    VALUE,
    ADDRESS,
    STRING,
} arg_type;

struct instruction {
    char mnemonic[4];
    uint8_t opcodes[8]; // The most opcodes for any single mnemonic is 8
    int *next;
};

struct directive {
    char operation[9]; // preemptively making this large enough to hold .include
                       // in case I ever add that functionality
    char *parameters;
};

struct label {
    char name[MAX_LBL_LEN + 1];
    uint16_t location;  // absolute location of label within file
    int *next;
};

struct operand {

};

struct line {};

#endif
