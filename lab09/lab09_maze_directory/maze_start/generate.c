/**************************************************
 * Author:      Bill Westrick
 * Lab:         Lab 9 starter (Lecture 09)
 * Description: Builds the maze. Your job is the carving.
 * ***********************************************/

#include "maze.h"
#include <stdio.h>


/* Fill the whole maze with wall, then carve the paths out of it.
 *
 * Filling is done. The carving is yours -- see the hints on the lab sheet:
 * walk at random from the start until you hit a dead end, then pick a random
 * square that is already path and walk again from there, until every path
 * square has been used.
 *
 * Remember the geometry: path squares are on odd rows and odd columns, and
 * the square between two of them is the wall you knock out to join them. So a
 * step moves two squares, and opens the one in between. */

#define NO_LEFT ((current_w < 3) || (maze[current_h][current_w - 2] != WALL))
#define NO_UP ((current_h < 3) || (maze[current_h - 2][current_w] != WALL))
#define NO_RIGHT ((current_w > w - 4) || (maze[current_h][current_w + 2] != WALL))
#define NO_DOWN ((current_h > h - 4) || (maze[current_h + 2][current_w] != WALL))

int next_h = 1;
int next_w = 1;

void get_next_cell(int x, int y)
{
    int next_direction = rand() % 2;
    int inc_or_dec = rand() % 2;

    next_h = y;
    next_w = x;

    if (inc_or_dec == 1) {
        inc_or_dec = 2;
    } else {
        inc_or_dec = -2;
    }

    if (next_direction == 0) {
        next_w += inc_or_dec;
    } else {
        next_h += inc_or_dec;
    }
}

void init_maze(int h, int w, char maze[h][w])
{
    for (int row = 0; row < h; row++)
        for (int col = 0; col < w; col++)
            maze[row][col] = WALL;

    maze[1][1] = PATH;                // the start is always open

    int current_h = 1;
    int current_w = 1;

    int path_stack_w[h/2 * w/2];
    int path_stack_h[h/2 * w/2];
    int stack_pos = 0;
    while(1)
    {
        maze[current_h][current_w] = PATH;

        if (NO_LEFT && NO_UP && NO_RIGHT && NO_DOWN)
        {
            current_h = path_stack_h[stack_pos];
            current_w = path_stack_w[stack_pos];
            --stack_pos;

        } else
        {
            while (1)
            {
                get_next_cell(current_w, current_h);
                if ((1 <= next_w && next_w < w - 1) && (1 <= next_h && next_h < h - 1) && (maze[next_h][next_w] == WALL))
                {
                    maze[next_h][next_w] = PATH;
                    maze[(next_h - current_h) / 2 + current_h][(next_w - current_w) / 2 + current_w] = PATH;

                    ++stack_pos;
                    path_stack_w[stack_pos] = current_w;
                    path_stack_h[stack_pos] = current_h;

                    current_w = next_w;
                    current_h = next_h;
                    break;
                }
            }
        }

        if (stack_pos == 0) // Stack position will only be zero when every cell
        {                   // has been visited, else there is still a path to follow.
            return;
        }
    }

}
