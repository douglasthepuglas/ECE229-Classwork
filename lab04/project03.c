/**************************************************
 * Author:      Douglas Cannizzaro
 * Lab:         Lab 4, project 3
 * Description: Reduces input fraction to simplest form using Euclid's Algorithm
 *              to find greatest common divisor of numerator and denominator
 * ***********************************************/

#include <stdio.h>
#include <stdbool.h>

int numerator = 0;
int denominator = 0;

// Placeholder addresses for gcd algorithm later.
int a1, a2, b1, b2;

int main(void) {
    printf("Enter integer fraction of form numerator/denominator: ");
    scanf("%d/%d", &numerator, &denominator);

    a1 = numerator;
    a2 = denominator;

    // Crude implementation of Euclid's Algorithm
    do {
        b1 = a2;
        b2 = a1 % a2;

        a1 = b1;
        a2 = b2;

    } while (a2 != 0);

    numerator /= a1;
    denominator /= a1;

    printf("Simplest form: %d/%d\n", numerator, denominator);


    return(0);
}
