/*
** EPITECH PROJECT, 2020
** can be droped
** File description:
** if a turret can be droped
*/

#include "struct.h"
#include "interface.h"

int return_price(int type)
{
    switch (type)
    {
    case 1: return 70;
        break;
    case 2: return 100;
        break;
    case 3: return 125;
        break;
    case 4: return 150;
        break;
    default:
        break;
    }
}

int can_be_droped(game_t *game, tower_emp_t *emp)
{
    sfVector2i mouse_pos = sfMouse_getPosition((sfWindow *)game[0].window);
    sfVector2f emp_pos;
    int i = 0;

    while (i != emp[0].nb_emp) {
        emp_pos = sfSprite_getPosition(emp[i].sprite);
        if (mouse_pos.x > emp_pos.x && mouse_pos.x < (emp_pos.x + 50) &&
            mouse_pos.y > emp_pos.y && mouse_pos.y < (emp_pos.y + 75)) {
                if (return_price(game[0].tower_type) < game[0].gold &&
                    emp[i].taken == 0) {
                    game[0].gold -= return_price(game[0].tower_type);
                    game[0].emp = i;
                    emp[i].taken = 1;
                    return 3;
                }
        }
        i++;
    }
    return 0;
}
