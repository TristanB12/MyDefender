/*
** EPITECH PROJECT, 2020
** tower
** File description:
** tower management
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "interface.h"
#include "tower.h"
#include "struct.h"
#include "my.h"
#include <stdlib.h>

tower_t *tower_create(tower_t *towers, int type)
{
    int i = 0;

    while (i < 40) {
        if (towers[i].active == 0 && towers[i].type == type) {
            towers[i].active = 1;
            return towers;
        }
        i++;
    }
    return towers;
}

tower_t *place_tower(tower_emp_t *emp, game_t game, tower_t *towers)
{
    sfVector2f pos_emp = sfSprite_getPosition(emp[game.emp].sprite);
    sfVector2f pos_tower;
    sfIntRect rect;
    int i = 0;
    int middle = 0;

    while (i < 40) {
        if (towers[i].active == 1) {
            rect = sfSprite_getTextureRect(towers[i].sprite);
            middle = rect.width / 2;
            pos_tower.x = pos_emp.x - (25 + middle - 50);
            pos_tower.y = pos_emp.y - (rect.height - 100);
            sfSprite_setPosition(towers[i].sprite, pos_tower);
            towers[i].active = 2;
            return towers;
        }
        i++;
    }
    return towers;
}

tower_t *tower_display(tower_t *towers, sfRenderWindow *window, sfVector2i pos)
{
    sfVector2f mouse_pos;
    sfIntRect tower_rect;

    int i = 0;

    while (i < 40) {
        if (towers[i].active == 1) {
            tower_rect = sfSprite_getTextureRect(towers[i].sprite);
            mouse_pos.x = pos.x - tower_rect.width / 2;
            mouse_pos.y = pos.y - tower_rect.height / 2;
            sfSprite_setPosition(towers[i].sprite, mouse_pos);
        }
        sfRenderWindow_drawSprite(window, towers[i].sprite, NULL);
        i++;
    }
    return towers;
}

tower_t *tower_drag(game_t *game, tower_t *towers, tower_emp_t *emp)
{
    sfVector2i pos = sfMouse_getPosition((sfWindow *)game[0].window);
    sfVector2f mouse_pos;
    sfIntRect tower_rect;

    if (game[0].create == 1) {
        towers = tower_create(towers, game[0].tower_type);
        game[0].drag = 1;
        game[0].create = 0;
    }
    if (game[0].drag == 0 && towers != NULL) {
        towers = destroy_last_tower(towers);
    }
    if (game[0].drag == 2)
        game[0].drag = can_be_droped(&game[0], emp);
    if (game[0].drag == 3) {
        towers = place_tower(emp, game[0], towers);
        game[0].drag = 0;
    }
    towers = tower_display(towers, game[0].window, pos);
    return towers;
}