/**************************************************
 * Author:      Bill Westrick
 * Lab:         Lab 9 starter (Lecture 09)
 * Description: Asks how big the maze should be, makes it, solves it, prints
 *              it. The making, the solving and the printing each live in
 *              their own file, and this one only knows their names -- which
 *              is the point of maze.h. Run "make" to build it.
 * ***********************************************/

#include "maze.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Big enough for a proper maze, small enough to fit on a screen -- and to keep
// a variable-length array comfortably on the stack. Only this file asks the
// user for a size, so only this file needs these.
#define MAX_WIDTH  200
#define MAX_HEIGHT 100

int main(void)
{
    int width, height;

    printf("How big is the maze? (enter width height): ");
    if (scanf("%d %d", &width, &height) != 2
        || width < 2 || height < 2 || width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Please enter a width from 2 to %d and a height from 2 to %d.\n",
               MAX_WIDTH, MAX_HEIGHT);
        return 1;
    }

    // Path squares sit on odd rows and odd columns, with a wall square between
    // any two of them -- like building a maze in Minecraft, where a wall needs
    // a block of its own. That only works out if both sizes are even.
    width  += width  % 2;
    height += height % 2;

    // The array is one bigger than the maze in each direction, for the wall
    // around the outside. Keeping that wall in the array is what lets the
    // solver step to a neighbour without first checking for the edge.
    int rows = height + 1;
    int cols = width + 1;
    char maze[rows][cols];

    srand((unsigned) time(NULL));

    init_maze(rows, cols, maze);

    // solve() says whether it found a way through. While you are still working
    // on init_maze, a maze that was not carved properly has no route, and this
    // is how you find that out -- otherwise a missing trail of breadcrumbs
    // leaves you guessing which of the two functions is wrong.
    if (!solve(rows, cols, maze, 1, 1))
        printf("No way through -- check that the maze was carved correctly.\n");

    //print_maze(rows, cols, maze);
    printf("done");

    return 0;
}
