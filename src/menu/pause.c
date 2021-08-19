/*
** EPITECH PROJECT, 2020
** pause
** File description:
** menu pause
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include "my.h"
#include "level.h"
#include "mobs.h"
#include "interface.h"
#include "menu.h"
#include <stdlib.h>
#include "struct.h"
#include "tower.h"
#include "spells.h"

int resume_game(sfRenderWindow *window)
{
    int resume = 0;
}

void pause_hover(sfRenderWindow *window, sfSprite *pause)
{
    sfVector2i pos_mouse = sfMouse_getPosition((sfWindow*)window);
    sfIntRect rect;

    rect = sfSprite_getTextureRect(pause);
    if ((pos_mouse.x > 816 && pos_mouse.x < 816 + 287) && (pos_mouse.y > 451
        && pos_mouse.y < 451 + 60)) {
        rect.top = 0;
        rect.left = 485;
        sfSprite_setTextureRect(pause, rect);
    }
    if ((pos_mouse.x > 816 && pos_mouse.x < 816 + 287) && (pos_mouse.y > 520
        && pos_mouse.y < 520 + 60)) {
        rect.top = 0;
        rect.left = 960;
        sfSprite_setTextureRect(pause, rect);
    }
    if ((pos_mouse.x > 816 && pos_mouse.x < 816 + 287) && (pos_mouse.y > 592
        && pos_mouse.y < 592 + 60)) {
        rect.top = 0;
        rect.left = 1442;
        sfSprite_setTextureRect(pause, rect);
        }
}

void pause_fct(sfRenderWindow *win, sfEvent evt, sfMusic **mus, sfSprite *pause)
{
    sfVector2i pos_mouse;
    sfFloatRect btn_rect;

    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        pos_mouse = sfMouse_getPosition((sfWindow *)win);
        btn_rect = sfSprite_getGlobalBounds(pause);
        if ((pos_mouse.x > 816 && pos_mouse.x < 816 + 287) && (pos_mouse.y > 451
        && pos_mouse.y < 451 + 60))
            game(1, win, evt, mus);
        if ((pos_mouse.x > 816 && pos_mouse.x < 816 + 287) && (pos_mouse.y > 520
            && pos_mouse.y < 520 + 60))
            display_btn(win, evt, mus);
        if ((pos_mouse.x > 816 && pos_mouse.x < 816 + 287) && (pos_mouse.y > 592
            && pos_mouse.y < 592 + 60))
            sfRenderWindow_destroy(win);
    }
}

void display_pause(sfRenderWindow *window, sfEvent event, sfMusic **music)
{
    sfIntRect pause_rect = create_rect(0, 0, 470, 314);
    sfVector2f pause_pos = create_vect(713, 383);
    sfSprite *pause = create_sprite("assets/pause.png", pause_rect, pause_pos);
    sfIntRect rect_bg = create_rect(0, 0, 1920, 1080);
    sfVector2f pos_bg = {0, 0};
    sfSprite *bg = create_sprite("assets/bg.png", rect_bg, pos_bg);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, bg, NULL);
        sfRenderWindow_drawSprite(window, pause, NULL);
        pause_hover(window, pause);
        pause_fct(window, event, music, pause);
        sfRenderWindow_display(window);
    }
}

void pause_button(sfRenderWindow *window, sfEvent event, sfMusic **music)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
        display_pause(window, event, music);
    }
}