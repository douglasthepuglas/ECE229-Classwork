/**************************************************
 * Author:      Douglas Cannizzaro
 * Lab:         exercise 2 page 71
 * Description: Reverse the order of digits of an input three-digit number.
 * ***********************************************/

#include <stdio.h>

int main(void)
{
    int input_number = 0;

    // Display prompt message
    printf("Enter a three-digit number: ");

    // Read user input to the input variable
    scanf("%d", &input_number);

    // Separate first, second, and third digits
    int first_digit = input_number / 100;
    int third_digit = input_number % 10;
    int second_digit = (input_number - (first_digit * 100) - third_digit) / 10;

    // Calculate new number by scaling original third digit by 100, the second
    // digit by 10 and summing both with the original first digit to acheive
    // integer output and display it
    int reverse_digits = (third_digit * 100) + (second_digit * 10) + first_digit;
    printf("The reversal is: %d\n\n", reverse_digits);

    return(0);
}