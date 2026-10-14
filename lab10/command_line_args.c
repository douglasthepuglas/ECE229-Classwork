/**************************************************
 * Author:      Bill Westrick
 * Lab:         Lecture 10 example
 * Description: Reports the command line arguments
 *              passed to the program
 * ***********************************************/
 
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    printf("There are %d arguments passed from the command line.\n", argc);
    
    for(int n=0; n<argc; ++n){
        printf("#%d => %s\n", n, argv[n]);
    }
    
    printf("\n\n");
    return 0;
}