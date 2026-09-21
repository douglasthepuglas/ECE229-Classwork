/**************************************************
 * Author:      Douglas Cannizzaro
 * Lab:         Lab 8, project 18
 * Description: Converted lab04_project03 to use recursion.
 ************************************************/

#include <stdio.h>

int get_gcd(int numerator, int denominator);

int main(void) {
    printf("Enter integer fraction of form numerator/denominator: ");
    int numerator, denominator;
    scanf("%d/%d", &numerator, &denominator);
    int gcd = get_gcd(numerator, denominator);

    int simple_num = numerator / gcd;
    int simple_denom = denominator / gcd;
    printf("Simplest form: %d/%d\n", simple_num, simple_denom);

    return(0);
}

int get_gcd(int numerator, int denominator) {
    int num_temp = denominator;
    int denom_temp = numerator % denominator;

    if (!denom_temp) {
        return(num_temp); // GCD ends up in num_temp when algorithm finishes
    }
    get_gcd(num_temp, denom_temp);
}


