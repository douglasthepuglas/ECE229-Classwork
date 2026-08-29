/**************************************************
 * Author:      Douglas Cannizzaro
 * Lab:         exercise 5 page 50
 * Description: Magic square checker. Enter numbers 1-16 in order such that
 *              every four numbers forms a row from top to bottom, then check if
 *              all rows, columns, and diagonals have the same sum.
 * ***********************************************/

 // I call this one "Fruit Loops"

#include <stdio.h>
#include <stdbool.h> /* I am familiar with boolean logic enough in other lan-
                      guages that I figured I'd look into how it works in C to
                      use it to check if the matrix is a valid magic square in-
                      program.
                      I was also bored and wanted to add to this assignment to
                      just give me something to do even though I technically
                      finished the lab earlier.
                    */

/*
   check_homogeneity checks if all elements in input array are equal, breaking
   at the first non-homogeneous entry if present.
   Later used for testing whether the input square is a magic square
*/
bool check_homogeneity(int array[], int size_array) {
    for(int n = 1; n < size_array; n++) {
        if(array[0] != array[n]) {
            return false;
            break;
        }
    }
    return true;
}

int main(void)
{
    // Use matrix for easier math with i indices for rows and j indices for
    // columns. I have taken linear algebra after all, so I may as well use it
    int input_nums[4][4] = {0};


    // Rows, columns, and diagonal variable declaration for later use
    // One entry in each array for each row/column/diagonal
    int row_sums[4] = {0};
    int col_sums[4] = {0};
    int diag_sum[2] = {0};

    printf("Enter numbers from 1 to 16 in any order:\n");


    // rows i, columns j for above matrix; same going forward
    for(int i = 0; i <= 3; i++) {
        for(int j = 0; j <= 3; j++) {
            scanf("%d", &input_nums[i][j]);
        }
    }

    // Calculate row sums, move to corresponding row_sums entry
    for(int i = 0; i <= 3; i++) {
        for(int j = 0; j <= 3; j++) {
            row_sums[i] += input_nums[i][j];
        }
    }

    // Do the same for column sums, swapping the positions of i and j
    for(int i = 0; i <= 3; i++) {
        for(int j = 0; j <= 3; j++) {
            col_sums[j] += input_nums[i][j];
        }
    }

    // Add top-left to bottom-right diagonal. k used because each value on this
    // diagonal has the same i and j value
    for(int k = 0; k <= 3; k++) {
        diag_sum[0] += input_nums[k][k];
    }

    // Add top-right to bottom-left diagonal. k used again to describe ith row
    // and "j = 3 - k"th row
    for(int k = 0; k <= 3; k++) {
        diag_sum[1] += input_nums[k][3 - k];
    }

    // defunct code optimized by new "Display full grid" section left in for
    // demonstration of improvement
    // printf("\n"); // Add space between entries above
    // for(int i = 0; i <= 3; i++) {
    //     printf("%d  %d  %d  %d\n\n", input_nums[i][0], input_nums[i][1], input_nums[i][2], input_nums[i][3]);
    // }

    // Display full grid; iterate over colums then rows
    printf("\n"); // Add space between entries above
    for(int i = 0; i <= 3; i++) {
        for(int j = 0; j<= 3; j++) {
            printf("%d  ", input_nums[i][j]);
        }
        printf("\n");
    }

    printf("\n"); // cushion between proceeding section

    // Display sums of each row, column, and diagonal
    printf("Row sums: %d  %d  %d  %d\n", row_sums[0], row_sums[1], row_sums[2], row_sums[3]);
    printf("Column sums: %d  %d  %d  %d\n", col_sums[0], col_sums[1], col_sums[2], col_sums[3]);
    printf("Diagonal sums: %d %d\n\n", diag_sum[0], diag_sum[1]);

    // Check and display if grid is a magic square
    if(!check_homogeneity(row_sums, 4)) {
        printf("Not a magic square :(\n\n");
    }
    else if(!check_homogeneity(col_sums, 4)) {
        printf("Not a magic square :(\n\n");
    }
    else if(!check_homogeneity(diag_sum, 2)) {
        printf("Not a magic square :(\n\n");
    }
    else {
        printf("Magic square :)\n\n");
    }

    return(0);
}
/* Side note (if the reader made it this far), this is legitemately the best
   code I have ever written and doing this gave me a bigger dopamine high than
   instagram reels has ever given me.
*/
