/*
** EPITECH PROJECT, 2020
** shot.c
** File description:
** management of shooting towers
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "my.h"
#include "level.h"
#include "mobs.h"
#include "interface.h"
#include <stdlib.h>
#include "struct.h"
#include "tower.h"
#include "spells.h"

void tower_range(tower_t *tower, mobs_t *mobs, game_t game)
{
    sfFloatRect mob_rect;
    sfFloatRect tower_rect;

    mob_rect = sfSprite_getGlobalBounds(mobs->sprite);
    tower_rect = sfSprite_getGlobalBounds(tower->sprite);

    if (((mob_rect.left <= tower_rect.left + tower->range
    || mob_rect.left >= tower_rect.left) && (mob_rect.top <= tower_rect.top
    + tower->range || mob_rect.top >= tower_rect.top)))
    mobs->life = mobs->life - tower->damage;
}
