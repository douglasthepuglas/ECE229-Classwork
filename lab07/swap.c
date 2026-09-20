/**************************************************
 * Author:      Bill Westrick
 * Lab:         Lecture 7 example
 * Description: uses pointers to swap two ints
 *              in a function
 * ***********************************************/

#include <stdio.h>

void swap(int *n, int *m); // function take two pointer to int

int main(void) {
  int n = 5;
  int m = 10;

  // show before state.
  printf("Before swap n = %d and m = %d\n", n, m);

  // do the swap.
  swap(&n, &m); // n and m are int. &n and &m are pointer to int.

  // show after state.
  printf("After swap n = %d and m = %d\n", n, m);

  printf("\n\n");
  return 0;
}

void swap(int *n, int *m) {
  int temp = *m; // swap the two ints using a temp int to help.
  *m = *n;
  *n = temp;
}