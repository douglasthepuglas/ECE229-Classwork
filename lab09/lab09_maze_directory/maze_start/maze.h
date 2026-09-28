/**************************************************
 * Author:      Bill Westrick
 * Lab:         Lab 9 starter (Lecture 09)
 * Description: What the maze's source files need to agree on. Anything used
 *              by more than one .c file belongs here, and nothing else does.
 *              The size limits are not here, for instance: only main.c uses
 *              them, so they live in main.c.
 * ***********************************************/
#ifndef MAZE_H
#define MAZE_H

#include <stdbool.h>
#include <stdlib.h>

// What a square of the maze can hold. All three files agree on these.
#define WALL  '#'
#define PATH  ' '
#define CRUMB '.'

/* generate.c -- fill the maze with wall, then carve the paths. */
void init_maze(int h, int w, char maze[h][w]);

/* solve.c -- find the way out from (row, col), leaving a trail of CRUMBs.
   Returns false if there is no way through. */
bool solve(int h, int w, char maze[h][w], int row, int col);

/* print.c -- write the maze to the screen. */
void print_maze(int h, int w, char maze[h][w]);

#endif
