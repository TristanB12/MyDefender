/*
** EPITECH PROJECT, 2020
** spells
** File description:
** spells
*/

#include "struct.h"
#include "interface.h"
#include "mobs.h"

#ifndef SPELLS_H_
#define SPELLS_H_

typedef struct s_spells
{
    int type;
    int active;
    int cooldown;
    sfSprite *sprite;
}spells_t;

spells_t *spell_init(void);
spells_t *spells(icons_spells_t *interface_spells, spells_t *spells, game_t *g);
spells_t change_rect_freeze(spells_t spell);
spells_t *spells_effects(spells_t *spells, mobs_t **mobs);
spells_t change_rect_zip(spells_t spell);
mobs_t *reset_mobs(mobs_t *mobs);
spells_t change_rect_sting(spells_t spell);

#endif /* !SPELLS_H_ */
