/**************************************************
 * Author:      Douglas Cannizzaro
 * Lab:         Lab 7, project 2
 * Description: Palindrome detector using pointers for string analysis.
 ************************************************/

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define BUFFER_LENGTH 255

bool is_palindrome(char *string, int length) {
    char *start = string;
    char *end = start + length - 1;

    // iterate over string from both ends, skipping non-letters, If any two
    // letter pairs from either end do not match, string is not a palindrome.
    while ((start <= end)) {
        while(!isalpha(*start)) {
            ++start;
        }

        while(!isalpha(*end)) {
            --end;
        }

        if (*start != *end) {
            return(false);
        }

        start += 1;
        end -= 1;
    }

    return (true);
}

int get_phrase(char *string, int max) {
    int n = 0;
    do {
        string[n] = toupper(getchar());
        n++;
    } while (string[n-1] != '\n');

    string[n-1] = 0;
    return(n-1);
}

int main(void) {
    char phrase[BUFFER_LENGTH];

    printf("Enter phrase: ");
    int length = get_phrase(phrase, BUFFER_LENGTH);

    if (is_palindrome(phrase, length)) {
        printf("Palindrome\n");
    }
    else {
        printf("Not a palindrome\n");
    }

    return(0);
}
