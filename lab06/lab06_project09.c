/**************************************************
 * Author:      Douglas Cannizzaro
 * Lab:         Lab 6, project 9
 * Description: Perform a random walk across a 10x10 array, moving up, down,
 *              left, or right by one cell according to what surrounding cells
 *              are free, printing the letters A-Z as it goes until either Z is
 *              printed or the path has no further available moves. Finally,
 *              print the resulting array.
 ************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define ARRAY_SIZE 10

// Used to simplify visual component of check
#define NO_LEFT (array[current_x - 1][current_y] != '.') && (current_x >= 0)
#define NO_UP (array[current_x][current_y - 1] != '.')
#define NO_RIGHT (array[current_x + 1][current_y] != '.')
#define NO_DOWN (array[current_x][current_y + 1] != '.')


// need to be in global space for function interoperability with main
int next_x = 0;
int next_y = 0;
char array[ARRAY_SIZE][ARRAY_SIZE];


// randomly pick next neighboring cell.
void get_next_cell(int x, int y) {
    int next_direction = random() % 2;
    int inc_or_dec = random() % 2;

    next_x = x;
    next_y = y;

    if (inc_or_dec == 1) {
        inc_or_dec = 1;
    } else {
        inc_or_dec = -1;
    }

    if (next_direction == 0) {
        next_x += inc_or_dec;
    } else {
        next_y += inc_or_dec;
    }
}


void print_matrix(char matrix[ARRAY_SIZE][ARRAY_SIZE]) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        for (int j = 0; j < ARRAY_SIZE; j++) {
            printf("%c ", matrix[i][j]);
        }

        printf("\n");
    }
    printf("\n\n");
}

int main(void) {
    srand((unsigned) time(NULL));
    char current_letter = 'A'; // adding int 1 to char goes along ascii codes.

    int current_x = 0;
    int current_y = 0;


    // initialize array to periods
    for (int i = 0; i < ARRAY_SIZE; i++) {
        for (int j = 0; j < ARRAY_SIZE; j++) {
            array[i][j] = '.';
        }
    }

    // set current x and y to next letter in sequence

    do {
        array[current_x][current_y] = current_letter;
        current_letter++; // ASCII is cool

        print_matrix(array);
        if (NO_LEFT && NO_UP && NO_RIGHT && NO_DOWN) {
            print_matrix(array);
            return(0);

        } else {
            while (1) {
                get_next_cell(current_x, current_y);
                if ((0 <= next_x && next_x < ARRAY_SIZE) && (0 <= next_y && next_y < ARRAY_SIZE) && (array[next_x][next_y] == '.')) {
                    current_x = next_x;
                    current_y = next_y;
                    break;
                }
            }
        }
    } while (current_letter - 1 != 'Z');

    return(0);
}
