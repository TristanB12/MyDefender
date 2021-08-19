/*
** EPITECH PROJECT, 2020
** tower
** File description:
** tower
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "struct.h"
#include "interface.h"

#ifndef TOWER_H_
#define TOWER_H_

typedef struct tower_s
{
    sfSprite *sprite;
    int type;
    int damage;
    int active;
    int actions;
    int range;
}tower_t;

tower_t *tower_drag(game_t *game, tower_t *towers, tower_emp_t *emp);
int can_be_droped(game_t *game, tower_emp_t *emp);
tower_t *destroy_last_tower(tower_t *towers);
tower_t *tower_init(tower_t *tower);

#endif /* !TOWER_H_ */
