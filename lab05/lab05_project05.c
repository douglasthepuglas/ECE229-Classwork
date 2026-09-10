/**************************************************
 * Author:      Douglas Cannizzaro
 * Lab:         Lab 5, project 7
 * Description: Determine value of input scrabble word.
 ************************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

// toupper

char *letters[] = {"AEILNORSTU", "DG", "BCMP", "FHVWY", "K", "JX", "QZ"};
int values[]     = {     1,        2,     3,      4,     5,    8,   10 };

int value_of_word = 5;

int letter_found_flag = 0;


int main(void) {
    printf("poo");
    value_of_word = 0;
    char word[15];
    printf("Enter scrabble word: ");
    scanf("%s", word);

    for (int i = 0; word[i] != 0; i++) {
        word[i] = toupper(word[i]);
    }

    for (int i = 0; word[i] != 0; i++) {
        printf("%d", i);
        letter_found_flag = 0;
        for (int j = 0; j < 7; j++) {
            for (int k = 0; k < (int)sizeof(letters[i]); k++) {
                if (word[i] == letters[j][k]) {
                    value_of_word += values[j];
                    letter_found_flag = 1;
                    break;
                }
            }

            if (letter_found_flag) {
                break;
            }
        }
    }

    //for letter in word
        //for letter value string
            //for letter in letter value string
                //check if same
                //if same
                    //break to

    //here

    printf("Word value: %d\n", value_of_word);
    return(0);
}
