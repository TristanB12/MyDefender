/*
** EPITECH PROJECT, 2020
** calcul vect
** File description:
** calcul vect between two points
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>

sfVector2f calcul_vect(sfVector2f position, int **cp, int pos_point)
{
    int x = cp[0][pos_point + 1];
    int y = cp[1][pos_point + 1];
    float dirx = x - position.x ;
    float diry = y - position.y;
    dirx *= 0.5;
    diry *= 0.5;
    sfVector2f direction = {dirx, diry};
    return direction;
}