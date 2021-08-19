/*
** EPITECH PROJECT, 2020
** tower init
** File description:
** tower init
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "interface.h"
#include "tower.h"
#include "struct.h"
#include "my.h"
#include <stdlib.h>

tower_t tower_create_struct(char *fp, sfIntRect rect, int type)
{
    tower_t tower;
    sfVector2f pos = {2000, 0};

    tower.active = 0;
    tower.actions = 0;
    tower.sprite = create_sprite(fp, rect, pos);
    tower.type = type;
    if (tower.type == 1)
        tower.damage = 30;
    if (tower.type == 2)
        tower.damage = 60;
    if (tower.type == 3)
        tower.damage = 80;
    else
        tower.damage = 9999;
    return tower;
}

tower_t *tower_init(tower_t *tower)
{
    int i = 0;
    sfIntRect rect1 = create_rect(0, 0, 161, 191);
    sfIntRect rect2 = create_rect(0, 0, 150, 355);
    sfIntRect rect3 = create_rect(0, 0, 333, 220);
    sfIntRect rect4 = create_rect(0, 0, 164, 373);

    tower = malloc(sizeof(tower_t) * 41);
    while (i < 10) {
        tower[i] = tower_create_struct("assets/archer-tower.png", rect1, 1);
        tower[10 + i] = tower_create_struct("assets/arbalet.png", rect2, 4);
        tower[20 + i] = tower_create_struct("assets/magic_tower.png", rect3, 2);
        tower[30 + i] = tower_create_struct("assets/stone_tower.png", rect4, 3);
        i++;
    }
    return tower;
}