/*
** EPITECH PROJECT, 2020
** mobs
** File description:
** mobs
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "level.h"

#ifndef MOBS_H_
#define MOBS_H_

typedef struct s_mobs
{
    sfSprite *sprite;
    int life;
    int total_life;
    sfVector2f dimension;
    double speed;
    int wave;
    int checkpoint;
    int deplacement;
    sfVector2f direction;
    int freeze;
    int destroy;
    sfSprite *life_bar;
    sfSprite *bg_bar;
    struct s_mobs *next;
}mobs_t;

mobs_t *mob_initialisation(level_t level_info);
void mob_display(sfRenderWindow *window, mobs_t *mobs);
mobs_t *mob_move(mobs_t *mobs, int **checkpoints, int spot_wave);
mobs_t *mob_change_rect(mobs_t *mobs);
mobs_t *mobs_life_init(mobs_t *mobs);
sfIntRect change_rect_life(mobs_t *mob);
void mobs_move(mobs_t *mobs);
mobs_t *mobs_set_position(mobs_t *mobs);
level_t change_wave(mobs_t *mobs, level_t level);

#endif /* !MOBS_H_ */
