/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "my.h"
#include "menu.h"

int main(int ac, char **av)
{
    sfRenderWindow *window;
    sfMusic *menu_music;
    sfIntRect rect = create_rect(0, 0, 1920, 1080);
    sfEvent event;
    sfVector2f pos = create_vect(0, 0);
    sfSprite *bg = create_sprite("assets/bg.png", rect, pos);
    sfVideoMode size = {1920, 1080 , 32};

    if (ac != 1)
        return 84;
    play_music("assets/menu.ogg", 10.0, &menu_music);
    window = sfRenderWindow_create(size, "defender", sfDefaultStyle, NULL);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
        menu(window, event, &menu_music);
        sfRenderWindow_display(window);
    }
}
