/*
** EPITECH PROJECT, 2020
** menu
** File description:
** Display and interact with the game menu
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include "my.h"
#include "menu.h"

void click_play(sfRenderWindow *win, sfEvent evt, sfSprite *play, sfMusic **sic)
{
    sfVector2i pos_mouse;
    sfFloatRect play_rect;

    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        pos_mouse = sfMouse_getPosition((sfWindow *)win);
        play_rect = sfSprite_getGlobalBounds(play);
        if ((pos_mouse.x > play_rect.left &&
            pos_mouse.x < play_rect.left + play_rect.width)
            && (pos_mouse.y > play_rect.top &&
            pos_mouse.y < play_rect.top + play_rect.height))
            disp_level_table(win, evt, sic);
        }
}

void menu(sfRenderWindow *win, sfEvent evt, sfMusic **menu)
{
    sfIntRect rect_play = create_rect(0, 0, 331, 329);
    sfIntRect rect_music = create_rect(0, 0, 176, 175);
    sfIntRect rect_name = create_rect(0, 0, 1100, 300);
    sfVector2f pos_name = {410, 200};
    sfVector2f pos_play = {795, 575};
    sfVector2f pos_music = {50, 50};
    sfSprite *name = create_sprite("assets/name.png", rect_name, pos_name);
    sfSprite *play = create_sprite("assets/play.png", rect_play, pos_play);
    sfSprite *music = create_sprite("assets/sic.png", rect_music, pos_music);
    sfIntRect rect = create_rect(0, 0, 1920, 1080);
    sfVector2f pos = create_vect(0, 0);
    sfSprite *bg = create_sprite("assets/bg.png", rect, pos);

    sfRenderWindow_drawSprite(win, bg, NULL);
    sfRenderWindow_drawSprite(win, name, NULL);
    sfRenderWindow_drawSprite(win, play, NULL);
    sfRenderWindow_drawSprite(win, music, NULL);
    click_play(win, evt, play, menu);
    quit_game(win, evt, menu);
    stop_mus(win, menu, evt, music);
}

void levels_sq(sfRenderWindow *window, sfEvent event, sfMusic **music)
{
    sfIntRect rect_level1 = create_rect(0, 0, 160, 159);
    sfIntRect rect_level2 = create_rect(0, 0, 160, 159);
    sfIntRect rect_level3 = create_rect(0, 0, 160, 159);
    sfVector2f pos1 = {598, 475};
    sfVector2f pos2 = {879, 475};
    sfVector2f pos3 = {1160, 475};
    sfSprite *level1 = create_sprite("assets/level_1.png", rect_level1, pos1);
    sfSprite *level2 = create_sprite("assets/level_2.png", rect_level2, pos2);
    sfSprite *level3 = create_sprite("assets/level3.png", rect_level3, pos3);
    sfRenderWindow_drawSprite(window, level1, NULL);
    sfRenderWindow_drawSprite(window, level2, NULL);
    sfRenderWindow_drawSprite(window, level3, NULL);
    click_lvl1(window, event, level1, music);
}

void level_table(sfRenderWindow *window, sfEvent event, sfMusic **music)
{
    sfIntRect rect_bg = create_rect(0, 0, 1920, 1080);
    sfVector2f pos_bg = {0, 0};
    sfSprite *bg = create_sprite("assets/bg.png", rect_bg, pos_bg);
    sfIntRect r_table = create_rect(0, 0, 966, 627);
    sfVector2f p_table = {477, 231};
    sfSprite *table = create_sprite("assets/menu_levels.png", r_table, p_table);

        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, bg, NULL);
        sfSprite_setPosition(table, p_table);
        sfRenderWindow_drawSprite(window, table, NULL);
        quit_lvl(window, event, music);
        levels_sq(window, event, music);
}

void quit_table(sfRenderWindow *win, sfEvent evt, sfMusic **music)
{
    sfIntRect quit_t_rect = create_rect(0, 0, 966, 627);
    sfVector2f quit_t_pos = {477, 231};
    sfSprite *qt = create_sprite("assets/qt.png", quit_t_rect, quit_t_pos);
    sfVector2i pos_mouse;

    sfRenderWindow_drawSprite(win, qt, NULL);
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        pos_mouse = sfMouse_getPosition((sfWindow *)win);
        if ((pos_mouse.x > 677 &&
            pos_mouse.x < 677 + 150)
            && (pos_mouse.y > 681 &&
            pos_mouse.y < 681 + 75))
            sfRenderWindow_destroy(win);
            sfMusic_destroy(music[0]);
        if ((pos_mouse.x > 1102 &&
            pos_mouse.x < 1102 + 150)
            && (pos_mouse.y > 691 &&
            pos_mouse.y < 691 + 70))
            display_menu(win, evt, music);
    }
}
