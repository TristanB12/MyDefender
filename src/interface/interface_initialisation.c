/*
** EPITECH PROJECT, 2020
** interface tower
** File description:
** manage tower icons in game interface
*/

#include "interface.h"
#include "my.h"
#include <stdlib.h>

icons_towers_t *interface_init_towers(void)
{
    icons_towers_t *towers = malloc(sizeof(icons_towers_t) * 4 + 1);
    sfIntRect rect = create_rect(450, 0, 150, 150);
    sfVector2f pos1 = create_vect(1770, 200);
    sfVector2f pos2 = create_vect(1770, 400);
    sfVector2f pos3 = create_vect(1770, 600);
    sfVector2f pos4 = create_vect(1770, 800);

    towers[0].sprite = create_sprite("assets/button_interface.png", rect, pos1);
    rect.left += 150;
    towers[1].sprite = create_sprite("assets/button_interface.png", rect, pos2);
    rect.left += 150;
    towers[2].sprite = create_sprite("assets/button_interface.png", rect, pos3);
    rect.left += 150;
    towers[3].sprite = create_sprite("assets/button_interface.png", rect, pos4);
    towers[0].type = 1;
    towers[1].type = 2;
    towers[2].type = 3;
    towers[3].type = 4;
    return towers;
}

icons_spells_t *interface_init_spells(void)
{
    icons_spells_t *spells = malloc(sizeof(icons_spells_t) * 3 + 1);
    sfIntRect rect = create_rect(0, 0, 150, 150);
    sfVector2f pos1 = create_vect(700, 830);
    sfVector2f pos2 = create_vect(900, 830);
    sfVector2f pos3 = create_vect(1100, 830);

    spells[0].sprite = create_sprite("assets/button_interface.png", rect, pos1);
    rect.left += 150;
    spells[1].sprite = create_sprite("assets/button_interface.png", rect, pos2);
    rect.left += 150;
    spells[2].sprite = create_sprite("assets/button_interface.png", rect, pos3);
    spells[0].type = 0;
    spells[1].type = 1;
    spells[2].type = 2;
    spells[0].cooldown = 0;
    spells[1].cooldown = 0;
    spells[2].cooldown = 0;
    return spells;
}

castle_life_t interface_init_life(void)
{
    sfIntRect bg_rect = create_rect(96, 0, 400, 50);
    sfIntRect life_rect = create_rect(96, 50, 400, 50);
    sfVector2f life_pos = create_vect(200, 20);
    castle_life_t life;

    life.bg = create_sprite("assets/life.png", bg_rect, life_pos);
    life.life_bar = create_sprite("assets/life.png", life_rect, life_pos);
    life.life = 100;
    return life;
}

interface_t interface_initialisation(void)
{
    interface_t interface;
    sfIntRect rect = {1050, 150, 150, 100};
    sfVector2f pos = {3000, 0};

    interface.tower = interface_init_towers();
    interface.spell = interface_init_spells();
    interface.life = interface_init_life();
    interface.nb_tower = -1;
    interface.actions = create_sprite("assets/button_interface.png", rect, pos);
    return interface;
}