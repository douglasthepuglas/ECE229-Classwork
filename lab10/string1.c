// string1.c

#include <stdio.h>

#define MSG "I am a symbolic constant string"
#define MAXLENGTH 81

int main(void)
{
    char words[MAXLENGTH] = "I am a string in an array.";
    const char *pt1 = "Something is pointing at me.";
    
    puts("Here are some strings:");
    puts(MSG);
    puts(words);
    puts(pt1);
    putchar(pt1[0]);
    words[8] = 'p';
    puts(words);
    
    return 0;
}

