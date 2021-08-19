/*
** EPITECH PROJECT, 2020
** interface
** File description:
** interface functions and struct
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "struct.h"

#ifndef INTERFACE_H_
#define INTERFACE_H_

typedef struct s_tower_interface
{
    sfSprite *sprite;
    int type;
}icons_towers_t;

typedef struct s_spells_interface
{
    sfSprite *sprite;
    int type;
    int cooldown;
}icons_spells_t;

typedef struct s_tower_emplacement
{
    sfSprite *sprite;
    int taken;
    int nb_emp;
}tower_emp_t;

typedef struct s_castle_life
{
    sfSprite *bg;
    sfSprite *life_bar;
    int life;
}castle_life_t;

typedef struct s_interface
{
    icons_towers_t *tower;
    icons_spells_t *spell;
    castle_life_t life;
    tower_emp_t *emp;
    sfSprite *actions;
    int nb_tower;
}interface_t;

interface_t interface_initialisation(void);
interface_t interface_management(game_t *game, interface_t interface);


#endif /* !INTERFACE_H_ */
