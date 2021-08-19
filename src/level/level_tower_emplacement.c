/*
** EPITECH PROJECT, 2020
** tower emplacement
** File description:
** tower management
*/

#include "interface.h"
#include "level.h"
#include <stdlib.h>
#include "my.h"

tower_emp_t *level1(void)
{
    tower_emp_t *emp = malloc(sizeof(tower_emp_t) * 6 + 1);
    sfIntRect rect = create_rect(0, 0, 50, 75);
    sfVector2f pos1 = create_vect(700, 575);
    sfVector2f pos2 = create_vect(975, 575);
    sfVector2f pos3 = create_vect(1425, 575);
    sfVector2f pos4 = create_vect(850, 225);
    sfVector2f pos5 = create_vect(1150, 225);
    sfVector2f pos6 = create_vect(1450, 225);

    emp[0].sprite = create_sprite("assets/tower_position.png", rect, pos1);
    emp[1].sprite = create_sprite("assets/tower_position.png", rect, pos2);
    emp[2].sprite = create_sprite("assets/tower_position.png", rect, pos3);
    emp[3].sprite = create_sprite("assets/tower_position.png", rect, pos4);
    emp[4].sprite = create_sprite("assets/tower_position.png", rect, pos5);
    emp[5].sprite = create_sprite("assets/tower_position.png", rect, pos6);
    emp[0].nb_emp = 6;
    for (int i = 0; i < 6; i++) {
        emp[i].taken = 0;
    }
    return emp;
}

level_t level_tower_emp(int level, level_t level_details)
{
    if (level == 1)
        level_details.towers = level1();
    return level_details;
}