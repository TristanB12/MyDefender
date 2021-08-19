/*
** EPITECH PROJECT, 2020
** win_loss_conditions
** File description:
** win loss conditions
*/

#include "interface.h"
#include "mobs.h"

int win_loss_conditions(mobs_t *mobs, castle_life_t life)
{
    if (life.life <= 0)
        return 1;
    if (mobs == NULL)
        return 2;
    return 0;
}

level_t change_wave(mobs_t *mobs, level_t level)
{
    mobs_t *tmp = mobs;
    int count = 0;

    while (tmp) {
        if (tmp->wave == level.spot_wave) {
            count++;
        }
        tmp = tmp->next;
    }
    if (count == 0)
        level.spot_wave++;
    return level;
}