/*
** EPITECH PROJECT, 2020
** spells rect
** File description:
** spells rect
*/

#include "struct.h"
#include "interface.h"
#include "spells.h"

spells_t change_rect_freeze(spells_t spell)
{
    sfIntRect rect = sfSprite_getTextureRect(spell.sprite);

    if (rect.left >= 1150)
        spell.active = 3;
    else {
        rect.left += 115;
    }
    sfSprite_setTextureRect(spell.sprite, rect);
    return spell;
}

spells_t change_rect_zip(spells_t spell)
{
    sfIntRect rect = sfSprite_getTextureRect(spell.sprite);

    if (rect.left >= 869)
        spell.active = 3;
    else {
        rect.left += 100;
    }
    sfSprite_setTextureRect(spell.sprite, rect);
    return spell;
}

spells_t change_rect_sting(spells_t spell)
{
    sfIntRect rect = sfSprite_getTextureRect(spell.sprite);

    if (rect.left >= 400)
        spell.active = 4;
    if (rect.left < 2100)
        rect.left += 83;
    sfSprite_setTextureRect(spell.sprite, rect);
    return spell;
}

mobs_t *reset_mobs(mobs_t *mobs)
{
    mobs_t *tmp = mobs;

    while (tmp) {
        tmp->freeze = 0;
        tmp = tmp->next;
    }
    return mobs;
}