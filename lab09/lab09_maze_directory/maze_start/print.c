/**************************************************
 * Author:      Bill Westrick
 * Lab:         Lab 9 starter (Lecture 09)
 * Description: Puts the maze on the screen. Nothing else in the program
 *              prints the maze, so if you take the H-option -- half-block
 *              characters and colour -- this is the only file you change.
 * ***********************************************/

#include "maze.h"

#include <stdio.h>

/* One character per square, one line per row, exactly as the maze is stored. */
void print_maze(int h, int w, char maze[h][w])
{
    for (int row = 0; row < h; row++) {
        for (int col = 0; col < w; col++)
            putchar(maze[row][col]);
        putchar('\n');
    }
}
