/**************************************************
 * Author:      Douglas Cannizzaro
 * Lab:         Lab 10, project 4
 * Description:
 ************************************************/

#include <stdio.h>


int main(int argc, char *argv[]) {
    printf("\n\n");
    for (int i = argc; i > 1; --i) {
        printf("%s ", argv[i - 1]);
    }

    printf("\n");
    return(0);
}
