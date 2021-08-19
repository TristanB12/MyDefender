/*
** EPITECH PROJECT, 2020
** level
** File description:
** level
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "interface.h"
#ifndef LEVEL_H_
#define LEVEL_H_

typedef struct level_mob
{
    int life;
    int speed;
    sfIntRect rect;
    sfVector2f position;
    sfVector2f dimension;
}level_mob_t;

typedef struct waves_details_s
{
    int nb_mob1;
    int nb_mob2;
    int nb_mob3;
    struct waves_details_s *next;
}level_wave_t;

typedef struct s_level
{
    char *bg_filepath;
    char *mobs_filepath;
    int **checkpoints;
    int nb_checkpoint;
    level_wave_t *waves;
    level_mob_t mob1;
    level_mob_t mob2;
    level_mob_t mob3;
    tower_emp_t *towers;
    int gold_earned;
    int spot_wave;
}level_t;

level_t level_checkpoints_initialisation(int level, level_t level_details);
level_t level_mobs_initialisation(int level, level_t level_details);
level_t level_initialisation(int level);
level_t level_wave_initialisation(int level, level_t level_details);
level_t level_tower_emp(int level, level_t level_details);

#endif /* !LEVEL_H_ */
