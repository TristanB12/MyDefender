/*
** EPITECH PROJECT, 2020
** change_window
** File description:
** functions that changes windows
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include "my.h"
#include "menu.h"
#include "struct.h"

void display_level_1(sfRenderWindow *window, sfEvent event, sfMusic **menu)
{
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfMusic_stop(menu[0]);
        game(1, window, event, menu);
        sfRenderWindow_display(window);
    }
}

void display_btn(sfRenderWindow *window, sfEvent event, sfMusic **music)
{
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
        menu(window, event, music);
        sfRenderWindow_display(window);
    }
}

void quit_lvl(sfRenderWindow *win, sfEvent evt, sfMusic **music)
{
    sfIntRect off_rect = create_rect(0, 0, 103, 104);
    sfVector2f pos_btn = {1337, 234};
    sfSprite *btn = create_sprite("assets/quit.png", off_rect, pos_btn);
    sfVector2i pos_mouse;
    sfFloatRect btn_rect;

    sfRenderWindow_drawSprite(win, btn, NULL);
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        pos_mouse = sfMouse_getPosition((sfWindow *)win);
            btn_rect = sfSprite_getGlobalBounds(btn);
            if ((pos_mouse.x > btn_rect.left &&
                pos_mouse.x < btn_rect.left + btn_rect.width)
                && (pos_mouse.y > btn_rect.top &&
                pos_mouse.y < btn_rect.top + btn_rect.height))
                display_btn(win, evt, music);
        }
}