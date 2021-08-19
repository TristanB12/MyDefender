/*
** EPITECH PROJECT, 2020
** quit
** File description:
** functions for quiting the game
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include "my.h"
#include "menu.h"

void display_quit(sfRenderWindow *win, sfEvent evt, sfMusic **music)
{
    while (sfRenderWindow_isOpen(win)) {
        while (sfRenderWindow_pollEvent(win, &evt)) {
            if (evt.type == sfEvtClosed)
                sfRenderWindow_close(win);
        }
        sfRenderWindow_clear(win, sfBlack);
        menu(win, evt, music);
        quit_table(win, evt, music);
        sfRenderWindow_display(win);
    }
}

void display_menu(sfRenderWindow *win, sfEvent evt, sfMusic **music)
{
    while (sfRenderWindow_isOpen(win)) {
        while (sfRenderWindow_pollEvent(win, &evt)) {
            if (evt.type == sfEvtClosed)
                sfRenderWindow_close(win);
        }
        sfRenderWindow_clear(win, sfBlack);
        menu(win, evt, music);
        sfRenderWindow_display(win);
    }
}