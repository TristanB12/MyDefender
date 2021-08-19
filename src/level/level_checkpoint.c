/*
** EPITECH PROJECT, 2020
** level_checkpoint
** File description:
** checkpoint initialisation
*/

#include "stdlib.h"
#include "level.h"

int **checkpoints_fill(int **checkpoints, int x, int y, int place)
{
    checkpoints[0][place] = x;
    checkpoints[1][place] = y;
    return checkpoints;
}

int **checkpoints_level1(int **checkpoints)
{
    checkpoints = malloc(sizeof(int *) * 2 + 1);
    checkpoints[0] = malloc(sizeof(int) * 10);
    checkpoints[1] = malloc(sizeof(int) * 10);
    checkpoints = checkpoints_fill(checkpoints, -500, 600, 0);
    checkpoints = checkpoints_fill(checkpoints, 200, 600, 1);
    checkpoints = checkpoints_fill(checkpoints, 300, 700, 2);
    checkpoints = checkpoints_fill(checkpoints, 1050, 750, 3);
    checkpoints = checkpoints_fill(checkpoints, 1200, 500, 4);
    checkpoints = checkpoints_fill(checkpoints, 1150, 400, 5);
    checkpoints = checkpoints_fill(checkpoints, 700, 350, 6);
    checkpoints = checkpoints_fill(checkpoints, 600, 75, 7);
    checkpoints = checkpoints_fill(checkpoints, 800, 50, 8);
    checkpoints = checkpoints_fill(checkpoints, 1920, 50, 9);
    return checkpoints;
}

level_t level_checkpoints_initialisation(int level, level_t level_details)
{
    int **cp = NULL;

    if (level == 1) {
        level_details.checkpoints = cp = checkpoints_level1(cp);
        level_details.nb_checkpoint = 9;
    }
    return level_details;
}