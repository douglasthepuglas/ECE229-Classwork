/**************************************************
 * Author:      Bill Westrick
 * Lab:         Lab 9 starter (Lecture 09)
 * Description: Solves the maze. Your job is the recursion.
 * ***********************************************/

#include "maze.h"

/* Find a way from (row, col) to the bottom-right path square, leaving a trail
 * of CRUMBs along the route that works. Returns false if there is none.
 *
 * Call this only on a square that is PATH -- main.c starts it at (1, 1), which
 * init_maze always leaves open, and each step below should check a square is
 * PATH before stepping onto it.
 *
 * Two things the shape below relies on:
 *
 *   A step moves ONE square, not two. Carving thinks in cells two apart;
 *   solving walks the squares it is given, the knocked-out walls included.
 *
 *   You never need to check for the edge of the array. The maze has a wall all
 *   the way around it, and a wall is not PATH, so the recursion stops there on
 *   its own. That is what the border is for -- do not remove it.
 *
 * The shape is here; the recursion is yours. */


#define LEFT maze[row][col - 1] == PATH
#define UP maze[row - 1][col] == PATH
#define RIGHT maze[row][col + 1] == PATH
#define DOWN maze[row + 1][col] == PATH

bool solve(int h, int w, char maze[h][w], int row, int col)
{
    maze[row][col] = CRUMB;           // leave a breadcrumb

    if (row == h - 2 && col == w - 2) { // the bottom-right corner: found it
        return true;
    }

    // Recursion time
    if (LEFT) {
        if (solve(h, w, maze, row, col - 1)) {
            return true;
        }
    }

    if (UP) {
        if (solve(h, w, maze, row - 1, col)) {
            return true;
        }
    }

    if (RIGHT) {
        if (solve(h, w, maze, row, col + 1)) {
            return true;
        }
    }

    if (DOWN) {
        if (solve(h, w, maze, row + 1, col)) {
            return true;
        }
    }

    maze[row][col] = PATH;            // every direction failed: pick the crumb up
    return false;
}
