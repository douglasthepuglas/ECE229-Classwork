/**************************************************
 * Author:      Douglas Cannizzaro
 * Lab:         Lab 4, project #5
 * Description: User enters earned income, program displays tax due for that
 *              income
 * ***********************************************/

#include <stdio.h>
#include <stdbool.h>

float income = 0.0;
float tax_due = 0.0;

int main(void) {
    printf("Enter earned income: ");
    scanf("%f", &income);

    if (income < 0) {
        printf("Invalid income.\n\n");
    } else if (income > 0 && income < 750) {
        tax_due = income * 0.01;

    } else if (income >= 750 && income < 2250) {
        tax_due = 7.50 + ((income - 750) * 0.02);

    } else if (income >= 2250 && income < 3750) {
        tax_due = 37.50 + ((income - 2250) * 0.03);

    } else if (income >= 3750 && income < 5250) {
        tax_due = 82.50 + ((income - 3750) * 0.04);

    } else if (income >= 5250 && income < 7000) {
        tax_due = 142.50 + (income - 3750) * 0.05;

    } else {
        tax_due = 230 + ((income - 7000) * 0.06);

    }

    if ((int)income != 0) {
        printf("Tax due: $%0.2f\n\n", tax_due);

    } else {
        printf("Tax due: $0.00\n\nf");

    }

    return(0);
}
