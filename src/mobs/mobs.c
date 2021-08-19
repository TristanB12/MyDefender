/*
** EPITECH PROJECT, 2020
** mobs
** File description:
** functions for mobs
*/

#include "mobs.h"
#include "level.h"
#include "my.h"
#include <stdlib.h>

mobs_t *mob_create_list(char *path, level_mob_t tmob, int nb_wave, mobs_t *mobs)
{
    mobs_t *element;
    mobs_t *tmp = mobs;

    while (tmp != NULL && tmp->next != NULL)
        tmp = tmp->next;
    element = malloc(sizeof(mobs_t));
    element->sprite = create_sprite(path, tmob.rect, tmob.position);
    element->life = tmob.life;
    element->speed = tmob.speed;
    element->wave = nb_wave;
    element->checkpoint = 0;
    element->dimension = tmob.dimension;
    element->deplacement = 0;
    element->destroy = 0;
    element->freeze = 0;
    element->next = NULL;
    if (tmp)
        tmp->next = element;
    else
        mobs = element;
    return mobs;
}

mobs_t *mob_initialisation(level_t level_info)
{
    level_wave_t *tmp = level_info.waves;
    int nb_wave = 1;
    mobs_t *mobs = NULL;
    char *path = level_info.mobs_filepath;

    while (tmp != NULL) {
        for (int i = 0; i < tmp->nb_mob1; i++) {
            mobs = mob_create_list(path, level_info.mob1, nb_wave, mobs);
        }
        for (int i = 0; i < tmp->nb_mob2; i++) {
            mobs = mob_create_list(path, level_info.mob2, nb_wave, mobs);
        }
        for (int i = 0; i < tmp->nb_mob3; i++) {
            mobs = mob_create_list(path, level_info.mob3, nb_wave, mobs);
        }
        nb_wave++;
        tmp = tmp->next;
    }
    mobs = mobs_life_init(mobs);
    mobs = mobs_set_position(mobs);
    return mobs;
}

void mob_display(sfRenderWindow *window, mobs_t *mobs)
{
    mobs_t *tmp = mobs;
    sfVector2f pos;

    while (tmp) {
        if (tmp->life != 0) {
            pos = sfSprite_getPosition(tmp->sprite);
            sfSprite_setPosition(tmp->bg_bar, pos);
            sfSprite_setPosition(tmp->life_bar, pos);
            sfSprite_setTextureRect(tmp->life_bar, change_rect_life(tmp));
            sfRenderWindow_drawSprite(window, tmp->bg_bar, NULL);
            sfRenderWindow_drawSprite(window, tmp->life_bar, NULL);
            sfRenderWindow_drawSprite(window, tmp->sprite, NULL);
        }
        tmp = tmp->next;
    }
}

mobs_t *mob_move(mobs_t *mobs, int **cp, int spot_wave)
{
    mobs_t *tmp = mobs;
    sfVector2f direction = {0, 0};
    sfVector2f pos;
    float x = 0;
    float y = 0;
    float norm = 0;

    while (tmp) {
        pos = sfSprite_getPosition(tmp->sprite);
        if (tmp->deplacement == 0 && tmp->wave == spot_wave) {
            x = cp[0][tmp->checkpoint + 1] - cp[0][tmp->checkpoint];
            y = cp[1][tmp->checkpoint + 1] - cp[1][tmp->checkpoint];
            norm = square_root(x * x + y * y, 5, x * x + y * y);
            x = (x / norm) * tmp->speed;
            y = (y /norm) * tmp->speed ;
            x = x * 0.2;
            y = y * 0.2;
            tmp->direction = create_vect(x, y);
            tmp->deplacement = 1;
        }
        else if ((pos.x > cp[0][tmp->checkpoint + 1] - 10) &&
        (pos.x < cp[0][tmp->checkpoint + 1] + 10) &&
        (pos.y > cp[1][tmp->checkpoint + 1] - 10) &&
        (pos.y < cp[1][tmp->checkpoint + 1] + 10) && tmp->wave == spot_wave) {
            tmp->checkpoint++;
            tmp->deplacement = 0;
        }
        tmp = tmp->next;
    }
    return mobs;
}

mobs_t *mob_change_rect(mobs_t *mobs)
{
    mobs_t *tmp = mobs;
    sfIntRect rect;

    while (tmp) {
        rect = sfSprite_getTextureRect(tmp->sprite);
        if (rect.left >= (tmp->dimension.x * 8))
            rect.left = 0;
        else {
            rect.left += tmp->dimension.x;
        }
        sfSprite_setTextureRect(tmp->sprite, rect);
        tmp = tmp->next;
    }
    return mobs;
}