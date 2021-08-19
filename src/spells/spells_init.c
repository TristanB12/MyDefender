/*
** EPITECH PROJECT, 2020
** spells
** File description:
** spells
*/

#include "struct.h"
#include "spells.h"
#include "my.h"
#include <stdlib.h>

spells_t spell_create_struct(sfIntRect rect, int type)
{
    spells_t spell;
    sfVector2f pos = {4000, 0};

    spell.active = 0;
    spell.cooldown = 0;
    spell.sprite = create_sprite("assets/spells.png", rect, pos);
    spell.type = type;
    return spell;
}

spells_t *spell_init(void)
{
    spells_t *spells = malloc(sizeof(spells_t) * 3);
    sfIntRect rect_freeze = create_rect(0, 70, 115, 85);
    sfIntRect rect_zip = create_rect(0, 0, 70, 70);
    sfIntRect rect_sting = create_rect(0, 225, 84, 130);

    spells[0] = spell_create_struct(rect_freeze, 1);
    spells[1] = spell_create_struct(rect_zip, 2);
    spells[2] = spell_create_struct(rect_sting, 3);
    return spells;
}