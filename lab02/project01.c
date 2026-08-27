/**************************************************
 * Author:      Douglas Cannizzaro
 * Lab:         exercise 1 page 71
 * Description: Reverse the order of digits of an input two-digit number.
 * ***********************************************/

#include <stdio.h>

int main(void)
{
    int input_number = 0;

    // Display prompt message
    printf("Enter a two-digit number: ");

    // Read user input to the input variable
    scanf("%d", &input_number);

    // Separate first and second numbers
    int first_digit = input_number / 10;
    int second_digit = input_number % 10;

    // Calculate new number by scaling original second digit by 10 and summing
    // with the original first digit to acheive integer output and display it
    int reverse_digit = (second_digit * 10) + first_digit;
    printf("The reversal is: %d\n\n", reverse_digit);

    return(0);
}