/*
** EPITECH PROJECT, 2020
** level
** File description:
** all info about level selected
*/

#include "level.h"

level_t level_mob_filepath(int level, level_t level_details)
{
    if (level == 1)
        level_details.mobs_filepath = "assets/mobs1.png";
    return level_details;
}

level_t level_bg_filepath(int level, level_t level_details)
{
    if (level == 1)
        level_details.bg_filepath = "assets/bg1.png";
    return level_details;
}

level_t level_initialisation(int level)
{
    level_t level_details;

    level_details = level_mob_filepath(level, level_details);
    level_details = level_bg_filepath(level, level_details);
    level_details = level_checkpoints_initialisation(level, level_details);
    level_details = level_mobs_initialisation(level, level_details);
    level_details = level_wave_initialisation(level, level_details);
    level_details = level_tower_emp(level, level_details);
    level_details.spot_wave = 1;
    return level_details;
}