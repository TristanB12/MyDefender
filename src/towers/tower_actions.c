/*
** EPITECH PROJECT, 2020
** tower remove
** File description:
** remove a tower
*/

#include "interface.h"
#include "tower.h"

int tower_is_clicked(tower_t *towers, sfRenderWindow *window)
{
    sfVector2f pos;
    sfIntRect rect;
    sfVector2i mouse_pos = sfMouse_getPosition((sfWindow *) window);

    for (int i = 0; i < 40; i++) {
        pos = sfSprite_getPosition(towers[i].sprite);
        rect = sfSprite_getTextureRect(towers[i].sprite);
        if (mouse_pos.x > pos.x && mouse_pos.x < (pos.x + rect.width) &&
            mouse_pos.y > pos.y && mouse_pos.y < (pos.y + rect.height)
            && towers[i].active == 2) {
                return i;
        }
    }
    return -1;
}

tower_t check_actions(tower_t t, interface_t i, sfRenderWindow *window)
{
    sfVector2i mouse_pos = sfMouse_getPosition((sfWindow *) window);
    sfVector2f actions_pos = sfSprite_getPosition(i.actions);
    sfVector2f basic_pos = {2000, 0};

    if (mouse_pos.x < actions_pos.x && mouse_pos.x < (actions_pos.x + 75) &&
        mouse_pos.y < actions_pos.y && mouse_pos.y < (actions_pos.y + 50)) {
        0;
    }
    if (mouse_pos.x < actions_pos.x + 75 && mouse_pos.x < (actions_pos.x + 150)
    && mouse_pos.y < actions_pos.y && mouse_pos.y < (actions_pos.y + 50)) {
        t.active = 0;
        sfSprite_setPosition(t.sprite, basic_pos);
    }
    return t;
}

interface_t create_actions(interface_t interface, tower_t tower)
{
    sfVector2f tower_pos = sfSprite_getPosition(tower.sprite);
    sfVector2f actions_pos;

    actions_pos.x = tower_pos.x;
    actions_pos.y = tower_pos.y - 100;
    sfSprite_setPosition(interface.actions, actions_pos);
    return interface;
}

int check_action_click(interface_t interface, sfRenderWindow *window)
{
    sfVector2i mouse_pos = sfMouse_getPosition((sfWindow *) window);
    sfVector2f actions_pos = sfSprite_getPosition(interface.actions);

    if (mouse_pos.x < actions_pos.x && mouse_pos.x < (actions_pos.x + 150) &&
        mouse_pos.y < actions_pos.y && mouse_pos.y < (actions_pos.y + 75)) {
        return 1;
    }
    return 0;
}

tower_t *tower_actions(tower_t *towers, game_t game, interface_t *interface)
{
    sfVector2f pos = {3000, 0};
    int nb_tower = 0;
    sfVector2f test;

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if ((nb_tower = tower_is_clicked(towers, game.window)) >= 0) {
            if (towers[nb_tower].actions == 0) {
                interface[0] = create_actions(interface[0], towers[nb_tower]);
                interface[0].nb_tower = nb_tower;
                towers[nb_tower].actions = 1;
            }
        }
        else {
            if (towers[interface[0].nb_tower].actions == 1 &&
                check_action_click(interface[0], game.window) == 1)
                towers[interface[0].nb_tower] = check_actions(
                towers[interface[0].nb_tower], interface[0], game.window);
            else {
                sfSprite_setPosition(interface[0].actions, pos);
                towers[interface[0].nb_tower].actions = 0;
                test = sfSprite_getPosition(interface[0].actions);
            }
        }
    }
    sfRenderWindow_drawSprite(game.window, interface[0].actions, NULL);
    return towers;
}