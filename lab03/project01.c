/**************************************************
 * Author:      Douglas Cannizzaro
 * Lab:         Lab 3, only homework
 * Description: User enters month, day, and year; program determines if year is
 *              a leap year and how many days into the year is the entered day.
 * ***********************************************/

#include <stdio.h>
#include <stdbool.h>


// Definitions done exclusively for readability
#define JAN 31
#define FEB 28 // leap year will add 1 if applicable
#define MAR 31
#define APR 30
#define MAY 31
#define JUN 30
#define JUL 31
#define AUG 31
#define SEP 30
#define OCT 31
#define NOV 30
#define DEC 31
int month_lengths[12] = {JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};

int main(void)
{
   // months =
    int month = 0;
    int day = 0;
    int year = 0;

    printf("Enter year: ");
    scanf("%d", &year);

    bool leap_year = !(year % 4);

    while(1) {
        printf("Enter month: ");
        scanf("%d", &month);

        if (month > 12 || month < 1) {
            printf("Invalid month\n\n");

        } else {
            break;

        }
    }

    while (1) {
        printf("Enter day: ");
        scanf("%d", &day);

        if (day > 31 || day < 1) {
            printf("Invalid day\n\n");

        } else if (!leap_year && month == 2 && day > 28) {
            printf("Invalid day\n\n");

        } else if (leap_year && month == 2 && day > 29) {
            printf("Invalid day\n\n");

        } else if (day > 30 && (month == 4 || month == 6 || month == 9 || 11)) {
            printf("Invalid day\n\n");

        } else {
            break;

        }
    }

    if(leap_year) {
        printf("%d is a leap year\n", year);
    } else {
        printf("%d is not a leap year \n", year);
    }

    return(0);
}
