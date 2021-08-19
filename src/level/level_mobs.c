/*
** EPITECH PROJECT, 2020
** level mob
** File description:
** template of mobs
*/

#include "level.h"
#include "my.h"

level_mob_t level_mob1(int level, sfVector2f vect)
{
    level_mob_t mob;

    if (level == 1) {
        mob.life = 500;
        mob.speed = 4;
        mob.rect = create_rect(0, 202, 155, 160);
        mob.dimension = create_vect(155, 319);
    }
    mob.position = vect;
    return mob;
}

level_mob_t level_mob2(int level, sfVector2f vect)
{
    level_mob_t mob;

    if (level == 1) {
        mob.life = 800;
        mob.speed = 3;
        mob.rect = create_rect(0, 362, 168, 177);
        mob.dimension = create_vect(168, 177);

    }
    mob.position = vect;
    return mob;
}

level_mob_t level_mob3(int level, sfVector2f vect)
{
    level_mob_t mob;

    if (level == 1) {
        mob.life = 1200;
        mob.speed = 2;
        mob.rect = create_rect(0, 0, 189, 202);
        mob.dimension = create_vect(189, 202);
    }
    vect;
    mob.position = vect;
    return mob;
}

level_t level_mobs_initialisation(int level, level_t level_details)
{
    sfVector2f vect;
    int x = level_details.checkpoints[0][0];
    int y = level_details.checkpoints[1][0];

    vect = create_vect(x, y);
    if (level == 1) {
        level_details.mob1 = level_mob1(level, vect);
        level_details.mob2 = level_mob2(level, vect);
        level_details.mob3 = level_mob3(level, vect);
    }
    return level_details;
}