/**************************************************
 * Author:      Bill Westrick
 * Lab:         Lecture 17 example
 * Description: will count the letters in the input
 *              file up to the EOF marker. Output
 *              the count for each letter and the total
 *              different letters used.
 * ***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{

    int count[26] = {0};            // array of 26 ints for letter counts

    char c;
    int n = 0;

    FILE *fp;       // file pointer for the input file.

    if(argc!=2){
         // if we done get 2 arguments, something is wrong
        printf("Usage: %s <filename.txt>\n",argv[0]);
        printf("Please provide a filename.\n");
        exit(EXIT_FAILURE);
    }

    // attempt to open the file...
    fp = fopen(argv[1],"r");
    if(fp == NULL){
        printf("Can't open file \"%s\"\n",argv[1]);
        exit(EXIT_FAILURE);
    }



    // read input
    do{
        c = getc(fp);     // get one char

        if(isalpha(c)){
            // make sure letter is capital
            char cap = toupper(c);
            ++count[cap - 'A'];    // increment the count for this letter.
        }

        ++n;
    }while(c != EOF); // done whne EOF is reached.


    // print results
    int total = 0;      // total number of letters
    int different = 0;  // number of different letters used
    for(int n=0; n<26; ++n){
        if(count[n]){
            ++different;
            total += count[n];
            printf("'%c' count = %d\n",'A'+ n,count[n]);
        }
    }

    fclose(fp); // close the file.

    printf("\nThere were %d total letters and %d different letters.\n", total, different);

    return 0;
}
