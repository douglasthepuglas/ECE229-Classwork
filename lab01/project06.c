/**************************************************
* Author: Douglas Cannizzaro
* Lab: exercise 6 page 35
* Description: Compute same polynomial from exercise 5 page 35 but using
*              Horner's Rule.
* ***********************************************/

#include <stdio.h>

int main(void)
{
    float x = 0;
    float result = 0;

    printf("Enter Value X: ");

    scanf("%f", &x);

    result = (((((3*x + 2)*x - 5)*x - 1)*x + 7)*x - 6);

    printf("Result = %.2f\n", result);

    return(0);

}