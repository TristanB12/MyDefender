/*
** EPITECH PROJECT, 2020
** create_sprite
** File description:
** lib function to create sprite
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>

sfSprite *create_sprite(char *path, sfIntRect rect, sfVector2f position)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = NULL;

    texture = sfTexture_createFromFile(path, NULL);
    sfTexture_setRepeated(texture, sfTrue);
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setPosition(sprite, position);
    return sprite;
}
