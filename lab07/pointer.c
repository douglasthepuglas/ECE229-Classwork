/**************************************************
 * Author:      Bill Westrick
 * Lab:         Lecture 7 example
 * Description: demo of pointer and negative indexes
 * ***********************************************/

#include <stdio.h>

void print_array(const char *name, const int *p, int start, int size);

int main(void) 
{
  int m[5] = {10, 20, 30, 40, 50};
  int *p = &m[2]; // p points to the third element in m;

  // array indexes can go negative
  print_array("m", m, 0, 5);
  
  // array indexes can go negative
  print_array("p", p, -2, 5);

  // pointer arithmetic
  print_array("(p-2)", p - 2, 0, 5);

  printf("\n\n");
  return 0;
}

void print_array(const char *name, const int *p, int start, int size) 
{
  // print size elemetns of the array.
  for (int n = 0; n < size; n++) {
    int index = n + start;
    printf("%s[%d] = %d \n", name, index, p[index]);
  }
  printf("\n");
}