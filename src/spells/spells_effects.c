/*
** EPITECH PROJECT, 2020
** effects spells
** File description:
** spell effect
*/

#include "struct.h"
#include "interface.h"
#include "spells.h"
#include "mobs.h"

mobs_t *mob_is_touched(mobs_t *mobs, spells_t spell, int type)
{
    sfFloatRect spell_rect = sfSprite_getGlobalBounds(spell.sprite);
    sfFloatRect mob_rect;
    mobs_t *tmp = mobs;

    while (tmp) {
        mob_rect = sfSprite_getGlobalBounds(tmp->sprite);
        if (sfFloatRect_intersects(&spell_rect, &mob_rect, NULL) == sfTrue) {
            if (type == 1)
                tmp->freeze = 1;
            if (type == 2)
                tmp->life -= 400;
            if (type == 3)
                tmp->life -= 1;
        }
        tmp = tmp->next;
    }
    return mobs;
}

spells_t spell_freeze(spells_t spell, mobs_t **mobs)
{
    spell = change_rect_freeze(spell);
    if (spell.active == 3) {
        mobs[0] = mob_is_touched(mobs[0], spell, 1);
    }
    return spell;
}

spells_t spell_zip(spells_t spell, mobs_t **mobs)
{
    spell = change_rect_zip(spell);
    if (spell.active == 3) {
        mobs[0] = mob_is_touched(mobs[0], spell, 2);
    }
    return spell;
}

spells_t spell_sting(spells_t spell, mobs_t **mobs)
{
    spell = change_rect_sting(spell);
    if (spell.active == 3 || spell.active == 4) {
        mobs[0] = mob_is_touched(mobs[0], spell, 3);
    }
    return spell;
}

spells_t *spells_effects(spells_t *spells, mobs_t **mobs)
{
    sfVector2f pos = {4000, 0};

    for (int i = 0; i < 3; i++) {
        if (spells[i].active == 2 || spells[i].active == 4) {
            if (spells[i].type == 1)
                spells[i] = spell_freeze(spells[i], mobs);
            if (spells[i].type == 2)
                spells[i] = spell_zip(spells[i], mobs);
            if (spells[i].type == 3)
                spells[i] = spell_sting(spells[i], mobs);
        }
        if (spells[i].active == 3) {
            spells[i].cooldown += 1;
            if (spells[i].cooldown >= 30) {
                spells[i].cooldown = 0;
                spells[i].active = 0;
                sfSprite_setPosition(spells[i].sprite, pos);
                mobs[0] = reset_mobs(mobs[0]);
            }
        }
    }
    return spells;
}