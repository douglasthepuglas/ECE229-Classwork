/**************************************************
 * Author:      Douglas Cannizzaro
 * Lab:         Lab 20, project 1
 * Description:
 ************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int str_to_int(const char *string);
int n_to_nbits(int number);

int main(void) {
    char input_option[3];

    printf("Binary to int (0) or int to on bits (1): ");
    fgets(input_option, 3, stdin);

    switch (input_option[0]) {
        case '0': {// this option select is dumb and horrible but it works as a bandaid to what I had before.
            char bin_input[34]; // Max bits + '\0'
            printf("Enter binary to convert to decimal: ");
            fgets(bin_input, 34, stdin);
            int b_to_i = str_to_int(bin_input);
            printf("Integer equivalent: %d\n", b_to_i);
            break;
        }
        case '1': {
            int input_num;
            int num_1s = 0;
            printf("Enter integer: ");
            scanf("%d", &input_num);
            num_1s = n_to_nbits(input_num);
            printf("Nubmber of 1s: %d.\n", num_1s);
            break;
        }
    }
    return(0);
}

int str_to_int(const char *in_string) {
    int int_value = 0;
    int length = strlen(in_string) - 1;
    for (int i = 0; in_string[i] != '\n'; ++i) {
        if (in_string[i] != '0' && in_string[i] != '1') {
            printf("Error: Invalid character.\n");
            exit(EXIT_FAILURE);
        }

        int_value <<= 1;
        if (in_string[i] == '1') {
            int_value += 1;
        }
    }

    return int_value;
}

int n_to_nbits(int number) {
    int mask = 1; // 0x00000001
    int num_1s = 0;
    for (int bit = 0; bit < 32; bit++) {
        num_1s += number & mask;
        number >>= 1;
    }
    return num_1s;
}