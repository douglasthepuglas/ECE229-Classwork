/**************************************************
 * Author:      Douglas Cannizzaro
 * Lab:         exercise 5 page 50
 * Description: Magic square checker. Enter numbers 1-16 in order such that
 *              every four numbers forms a row from top to bottom, then check if
 *              all rows, columns, and diagonals have the same sum.
 * ***********************************************/

 // I call this one "Fruit Loops"

#include <stdio.h>

int main(void)
{
    // Use matrix for easier math with i indices for rows and j indices for
    // columns.
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
            col_sums[i] += input_nums[i][j];
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

    // Display full grid
    printf("\n"); // Add space between entries above
    for(int i = 0; i <= 3; i++) {
        printf("%d  %d  %d  %d\n\n", input_nums[i][0], input_nums[i][1], input_nums[i][2], input_nums[i][3]);
    }

    // Display sums of each row, column, and diagonal
    printf("Row sums: %d  %d  %d  %d\n", row_sums[0], row_sums[1], row_sums[2], row_sums[3]);
    printf("Column sums: %d  %d  %d  %d\n", col_sums[0], col_sums[1], col_sums[2], col_sums[3]);
    printf("Diagonal sums: %d %d\n", diag_sum[0], diag_sum[1]);

    return(0);
}