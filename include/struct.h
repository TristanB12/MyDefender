/*
** EPITECH PROJECT, 2020
** struct
** File description:
** struct
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct s_game
{
    sfRenderWindow *window;
    sfEvent event;
    sfText *gold_text;
    int gold;
    int drag;
    int drag_spell;
    int tower_type;
    int create;
    int emp;
}game_t;

#endif /* !STRUCT_H_ */
