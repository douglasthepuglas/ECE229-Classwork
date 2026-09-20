/**************************************************
 * Author:      Douglas Cannizzaro
 * Lab:         Lab 07, project 3
 * Description: Rewrite of Lab04 Project 3 using a function and pointers
 ************************************************/

#include <stdio.h>



void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator) {
    int temp_numerator_1 = numerator;
    int temp_denominator_1 = denominator;
    int temp_numerator_2;
    int temp_denominator_2;

    do {
        temp_numerator_2 = temp_denominator_1;
        temp_denominator_2 = temp_numerator_1 % temp_denominator_1;

        temp_numerator_1 = temp_numerator_2;
        temp_denominator_1 = temp_denominator_2;

    } while (temp_denominator_1 != 0);

    *reduced_numerator = numerator / temp_numerator_1;
    *reduced_denominator = denominator / temp_numerator_1;
}

int main(void) {
    int numerator = 0;
    int denominator = 0;
    int final_numerator;
    int final_denominator;

    int *reduced_numerator = &final_numerator;
    int *reduced_denominator = &final_denominator;

    printf("Enter integer fraction of form numerator/denominator: ");
    scanf("%d/%d", &numerator, &denominator);

    reduce(numerator, denominator, reduced_numerator, reduced_denominator);

    printf("Simplest form: %d/%d\n", final_numerator, final_denominator);

    return(0);
}
