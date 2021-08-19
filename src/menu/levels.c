/*
** EPITECH PROJECT, 2020
** levels
** File description:
** click level management
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include "my.h"
#include "menu.h"
#include "struct.h"

void click_lvl1(sfRenderWindow *win, sfEvent evt, sfSprite *lvl1, sfMusic **sic)
{
    sfVector2i pos_mouse;
    sfFloatRect level1_rect;

    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        pos_mouse = sfMouse_getPosition((sfWindow *)win);
            level1_rect = sfSprite_getGlobalBounds(lvl1);
            if ((pos_mouse.x > level1_rect.left &&
                pos_mouse.x < level1_rect.left + level1_rect.width)
                && (pos_mouse.y > level1_rect.top &&
                pos_mouse.y < level1_rect.top + level1_rect.height)) {
                display_level_1(win, evt, sic);
            }
        }
}

void disp_level_table(sfRenderWindow *win, sfEvent evt, sfMusic **music)
{
    sfIntRect rect = create_rect(0, 0, 1920, 1080);
    sfVector2f pos = create_vect(0, 0);
    sfSprite *bg = create_sprite("assets/bg.png", rect, pos);

    while (sfRenderWindow_isOpen(win)) {
        while (sfRenderWindow_pollEvent(win, &evt)) {
            if (evt.type == sfEvtClosed)
                sfRenderWindow_close(win);
        }
        sfRenderWindow_clear(win, sfBlack);
        sfRenderWindow_drawSprite(win, bg, NULL);
        level_table(win, evt, music);
        sfRenderWindow_display(win);
    }
}

void quit_game(sfRenderWindow *window, sfEvent evt, sfMusic **music)
{
    sfIntRect quit_rect = create_rect(0, 0, 103, 104);
    sfVector2f quit_pos = {1767, 50};
    sfSprite *quit_btn = create_sprite("assets/quit.png", quit_rect, quit_pos);
    sfVector2i pos_mouse;
    sfFloatRect btn_rect;

    sfRenderWindow_drawSprite(window, quit_btn, NULL);
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        pos_mouse = sfMouse_getPosition((sfWindow *)window);
            btn_rect = sfSprite_getGlobalBounds(quit_btn);
            if ((pos_mouse.x > btn_rect.left &&
                pos_mouse.x < btn_rect.left + btn_rect.width)
                && (pos_mouse.y > btn_rect.top &&
                pos_mouse.y < btn_rect.top + btn_rect.height))
                display_quit(window, evt, music);
        }
}