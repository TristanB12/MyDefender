/*
** EPITECH PROJECT, 2020
** mob set position
** File description:
** mob set position
*/

#include "mobs.h"
#include "level.h"
#include "my.h"

mobs_t *mobs_set_position(mobs_t *mobs)
{
    mobs_t *tmp = mobs;
    sfVector2f pos;
    int place = 0, place2 = 0, place3 = 0;

    for (; tmp != NULL; tmp = tmp->next) {
        pos = sfSprite_getPosition(tmp->sprite);
        if (tmp->wave == 1) {
            pos.x -= place;
            place += 100;
        }
        if (tmp->wave == 2) {
            pos.x -= place2;
            place2 += 100;
        }
        else {
            pos.x -= place3;
            place3 += 100;
        }
        sfSprite_setPosition(tmp->sprite, pos);
    }
    return mobs;
}

