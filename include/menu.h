/*
** EPITECH PROJECT, 2020
** menu
** File description:
** macros and prototypes for the menu
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

#ifndef __MENU__
#define __MENU__

    void menu(sfRenderWindow *win, sfEvent evt, sfMusic **menu);
    void level_table(sfRenderWindow *window, sfEvent event, sfMusic **music);
    void click_lvl1(sfRenderWindow *win, sfEvent evt, sfSprite *lvl1, sfMusic **sic);
    void click_lvl2(sfRenderWindow *win, sfEvent evt, sfSprite *lvl2, sfMusic **sic);
    void click_lvl3(sfRenderWindow *win, sfEvent evt, sfSprite *lvl3, sfMusic **sic);
    void play_music(char *path, float volume, sfMusic **menu_music);
    void stop_mus(sfRenderWindow *win, sfMusic **menu, sfEvent evt, sfSprite *mus);
    void quit_lvl(sfRenderWindow *win, sfEvent evt, sfMusic **mus);
    void disp_level_table(sfRenderWindow *win, sfEvent evt, sfMusic **music);
    void display_level_1(sfRenderWindow *window, sfEvent event, sfMusic **menu);
    void display_level_2(sfRenderWindow *window, sfEvent event);
    void display_level_3(sfRenderWindow *window, sfEvent event);
    void quit_game(sfRenderWindow *window, sfEvent evt, sfMusic **music);
    void display_btn(sfRenderWindow *window, sfEvent event, sfMusic **music);
    void quit_table(sfRenderWindow *win, sfEvent evt, sfMusic **music);
    void display_quit(sfRenderWindow *win, sfEvent evt, sfMusic **music);
    void display_menu(sfRenderWindow *win, sfEvent evt, sfMusic **music);
    void pause_button(sfRenderWindow *window, sfEvent event, sfMusic **music);

#endif
