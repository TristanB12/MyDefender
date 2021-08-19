/*
** EPITECH PROJECT, 2020
** level wave
** File description:
** give the details of waves among the selected level
*/

#include "level.h"
#include "stdlib.h"

level_wave_t *level_wave_fill(int mob1, int mob2, int mob3, level_wave_t *waves)
{
    level_wave_t *element;
    level_wave_t *tmp = waves;

    while (tmp != NULL && tmp->next != NULL) {
        tmp = tmp->next;
    }
    element = malloc(sizeof(level_wave_t));
    element->nb_mob1 = mob1;
    element->nb_mob2 = mob2;
    element->nb_mob3 = mob3;
    element->next = NULL;
    if (tmp)
        tmp->next = element;
    else
        waves = element;

    return waves;
}

level_t level_wave_initialisation(int level, level_t level_details)
{
    level_details.waves = NULL;
    if (level == 1) {
        level_details.waves = level_wave_fill(2, 2, 1, level_details.waves);
        level_details.waves = level_wave_fill(4, 2, 2, level_details.waves);
        level_details.waves = level_wave_fill(5, 2, 3, level_details.waves);
    }
    return level_details;
}