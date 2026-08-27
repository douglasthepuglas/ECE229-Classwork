/**************************************************
 * Author:      Douglas Cannizzaro
 * Lab:         exercise 5 page 50
 * Description: Describe what the program will do
 * ***********************************************/

 #include <stdio.h>

int main(void)
{
    int input_nums[16];

    printf("Enter numbers from 1 to 16 in any order:\n");

    for(int i = 0; i <= 15; i++) {
        scanf("%d", &input_nums[i]);

    }

    for(int i = 0; i <= 15; i += 4) {
        printf("%-d   %-d   %-d   %-d\n", input_nums[i], input_nums[i + 1], input_nums[i + 2], input_nums[i + 3]);

    }

    return(0);
}