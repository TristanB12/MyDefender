/*
** EPITECH PROJECT, 2020
** music
** File description:
** music management
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include "my.h"
#include "menu.h"

void play_music(char *path, float volume, sfMusic **menu_music)
{
    menu_music[0] = sfMusic_createFromFile(path);
    sfMusic_setVolume(menu_music[0], volume);
    sfMusic_play(menu_music[0]);
}

void draw_no_mus(sfRenderWindow *win, sfEvent evt, sfMusic **sic, sfSprite *mus)
{
    sfIntRect rect = create_rect(0, 0, 175, 175);
    sfVector2f pos = {50, 50};
    sfSprite *no_music = create_sprite("assets/off.png", rect, pos);

    while (sfRenderWindow_isOpen(win)) {
        while (sfRenderWindow_pollEvent(win, &evt)) {
            if (evt.type == sfEvtClosed)
                sfRenderWindow_close(win);
        }
        sfRenderWindow_clear(win, sfBlack);
        menu(win, evt, sic);
        sfSprite_destroy(mus);
        sfRenderWindow_drawSprite(win, no_music, NULL);
        sfRenderWindow_display(win);
    }
}

void stop_mus(sfRenderWindow *win, sfMusic **menu, sfEvent evt, sfSprite *mus)
{
    sfVector2i pos_mouse;
    sfFloatRect music_rect;

    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        pos_mouse = sfMouse_getPosition((sfWindow *)win);
            music_rect = sfSprite_getGlobalBounds(mus);
            if ((pos_mouse.x > music_rect.left &&
                pos_mouse.x < music_rect.left + music_rect.width)
                && (pos_mouse.y > music_rect.top &&
                pos_mouse.y < music_rect.top + music_rect.height)) {
                sfMusic_stop(menu[0]);
                draw_no_mus(win, evt, menu, mus);
                }
        }
}