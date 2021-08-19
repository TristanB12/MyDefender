/*
** EPITECH PROJECT, 2020
** create_rect
** File description:
** function csfml to init sfIntRect
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>

sfIntRect create_rect(int l, int t, int w, int h)
{
    sfIntRect rect;

    rect.left = l;
    rect.top = t;
    rect.width = w;
    rect.height = h;
    return rect;
}
