/**************************************************
 * Author:      Bill Westrick
 * Lab:         Lecture 7 example
 * Description: Uses pointer arithmetic to reverse
 *              an input string.
 * ***********************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define BUFFER_SIZE 255

int get_sentence(char *str,int max);
char *reverse_string(char *str);
 
int main(void){

    char sentence[BUFFER_SIZE];     // buffer to hold sentence
    int index;
    
    get_sentence(sentence,BUFFER_SIZE);
    
    printf("Your sentence in reverse:\n");
    printf("%s\n",reverse_string(sentence));

    printf("\nBye.\n");
    
    return 0;

}


// given a char array buffer, ask the user to input a sentence
// the sentence will be a string in the buffer
// return the string length
int get_sentence(char *str, int max)
{
    int n=0;
    
    // get input sentence
    printf("Enter a sentence, press enter when done...\n");
    do{
       str[n] = getchar();   // read one char at a time
       ++n;
    }while(str[n-1] != '\n' && n<max); // until the user enters \n or max chars is reached
    
    str[n-1] = '\0'; // replace last \n with a null trerminator so we can use snetence as a string.
    
    return n-1;     // strlen
}


// reverses a string in place
char *reverse_string(char *str)
{
    char *start = str;  // pointer to the start of teh string
    char *end = str + strlen(str) - 1; // pointer to the last char in teh string.
    
    while(start < end){ // swap chars until start and end meet at the center of the string.
        char temp = *start;
        *start = *end;
        *end = temp;
        ++start;    // increments the start pointer moving it one char forward.
        --end;      // decrements the end pointer moving it one char backward.
    }
    
    return str;
}
