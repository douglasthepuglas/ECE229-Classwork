/**************************************************
 * Author:      Douglas Cannizzaro
 * Lab:         Lab 12, project 5
 * Description: Sum all integer arguments in program call.
 ************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int sum = 0;
    for (int i = 1; i < argc; ++i) {
        int argument = atoi(argv[i]);
        sum += argument;
    }

    printf("Sum: %d\n", sum);
    return(0);
}
