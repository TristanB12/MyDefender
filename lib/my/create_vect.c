/*
** EPITECH PROJECT, 2020
** create_vect
** File description:
** sfml function
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>

sfVector2f create_vect(float x, float y)
{
    sfVector2f vect;

    vect.x = x;
    vect.y = y;
    return vect;
}