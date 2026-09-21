/**************************************************
 * Author:      Douglas Cannizzaro
 * Lab:         Lab 6, project 06
 * Description: Translate input message to "B1ff language" by first
 *              capitalizing the entire message, then replacting any instance of
 *              an entry in b1ff_letters with the corresponding character in
 *              b1ff_replace, then finally appending a random amount of
 *              exclamation marks to the end of the message.
 ************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define BUFFER_SIZE 255

const char b1ff_letters[] = "ABEIOS";
const char b1ff_replace[] = "483105";


// Take input character, return b1ff equivalent
char b1ffinator(char letter) {
    int index = 0;
    while (1) {
        if (letter == b1ff_letters[index]) {
            return(b1ff_replace[index]);
        } else if (index == 5) {
            return(letter);
        }

        index++;
    }
}

// Roughly copied code from reverse.c with permission from Bill because this
// isn't required for the assignment and I'm extra wit it. My implementation
// would have been fugly with a while (1) loop with a get_char followed by an
// if (character != '\n' && n < max), but the example implementation is
// objectively better.


int get_sentence(char str[], int max) {
    int n = 0;
    do {
        str[n] = getchar();
        n++;

    } while (str[n-1] != '\n' && n < max);

    str[n-1] = '\0';

    return(n - 1);
}


int main(void) {
    char message[BUFFER_SIZE];
    srand((unsigned) time(NULL));

    printf("Enter a phrase to be B1ffinated: \n");

    // Calling get_sentence even as an initializer gets the sentence,
    // but since it returns the message length as an int that we need to know,
    // it simplifies the code to double the function call's purpose.
    int size_of_message = get_sentence(message, BUFFER_SIZE);

    for (int i = 0; i < size_of_message; i++) {
        message[i] = toupper(message[i]);
        message[i] = b1ffinator(message[i]);
    }

    int exclamation_marks = (rand() % 5) + 8; // +8 ensures there will always
                                              // be some exclamation marks even
                                              // if % 5 = 0

    // ensure that adding exclamation marks won't exceed the buffer
    if ((size_of_message) + exclamation_marks >= BUFFER_SIZE) {
        exclamation_marks = BUFFER_SIZE - size_of_message - 1;
    }


    for (int i = 1; i <= exclamation_marks; i++) {
        message[size_of_message - 1 + i] = '!';
    }

    printf("Biffinated phrase:\n%s\n", message);

    return(0);
}
