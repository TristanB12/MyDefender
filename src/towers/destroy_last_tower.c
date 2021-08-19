/*
** EPITECH PROJECT, 2020
** destroy last tower
** File description:
** destroy last tower
*/

#include "tower.h"

tower_t *destroy_last_tower(tower_t *towers)
{
    int i = 0;
    sfVector2f pos = {2000, 0};

    while (i < 40) {
        if (towers[i].active == 1) {
            towers[i].active = 0;
            sfSprite_setPosition(towers[i].sprite, pos);
        }
        i++;
    }
    return towers;
}