/*
** EPITECH PROJECT, 2020
** change rect
** File description:
** change rect
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>

sfIntRect change_rect(int l, int t, sfIntRect rect)
{
    if (l != -1)
        rect.left = l;
    if (t != -1)
    rect.top = t;
    return rect;
}