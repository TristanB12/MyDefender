/*
** EPITECH PROJECT, 2020
** mob life
** File description:
** mob life
*/

#include "mobs.h"
#include "level.h"
#include "my.h"
#include <stdlib.h>

sfIntRect change_rect_life(mobs_t *mob)
{
    sfIntRect rect = sfSprite_getTextureRect(mob->life_bar);

    rect.width = (mob->life * 96) / mob->total_life;
    return rect;
}

mobs_t *mobs_life_init(mobs_t *mobs)
{
    mobs_t *tmp = mobs;
    sfIntRect rect_bg = create_rect(0, 0, 96, 14);
    sfIntRect rect_life = create_rect(0, 14, 96, 14);
    sfVector2f pos;

    while (tmp) {
        pos = sfSprite_getPosition(tmp->sprite);
        tmp->bg_bar = create_sprite("assets/life.png", rect_bg, pos);
        tmp->life_bar = create_sprite("assets/life.png", rect_life, pos);
        tmp->total_life = tmp->life;
        tmp = tmp->next;
    }
    return mobs;
}

void mobs_move(mobs_t *mobs)
{
    mobs_t *tmp = mobs;

    while (tmp) {
        if (tmp->freeze == 0)
            sfSprite_move(tmp->sprite, tmp->direction);
        tmp = tmp->next;
    }
}