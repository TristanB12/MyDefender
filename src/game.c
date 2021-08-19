/*
** EPITECH PROJECT, 2020
** main
** File description:
** test main
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include "my.h"
#include "level.h"
#include "mobs.h"
#include "menu.h"
#include "interface.h"
#include <stdlib.h>
#include "struct.h"
#include "tower.h"
#include "spells.h"

int win_loss_conditions(mobs_t *mobs, castle_life_t life);

mobs_t *mob_supp(mobs_t *mobs)
{
    mobs_t *tmp = mobs;
    mobs_t *first_elem = NULL;
    mobs_t *last_elem = NULL;

    int i = 0;

    if (tmp->next == NULL && tmp->destroy == 1)
        mobs = NULL;
    else if (tmp->destroy == 1)
        mobs = mobs->next;
    else {
        while (tmp->next->destroy != 1)
            tmp = tmp->next;
        tmp->next = tmp->next->next;
    }
    return mobs;
}

mobs_t *mob_man(sfRenderWindow *w, mobs_t *m, level_t *l, castle_life_t *life)
{
    mobs_t *tmp = m;
    int place = 0;

    m = mob_move(m, l[0].checkpoints, l[0].spot_wave);
    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->checkpoint == l[0].nb_checkpoint &&
            tmp->wave == l[0].spot_wave) {
            life[0].life -= (tmp->total_life / 100);
            tmp->destroy = 1;
            m = mob_supp(m);
        }
        if (tmp->life <= 0) {
            tmp->destroy = 1;
            m = mob_supp(m);
            l[0].gold_earned = tmp->total_life / 5;
        }
        place++;
    }
    mob_display(w, m);
    return m;
}

sfText *text_init(void)
{
    sfText *text = sfText_create();
    sfVector2f pos = {10, 0};
    sfFont * font = sfFont_createFromFile("assets/font.ttf");

    sfText_setCharacterSize(text, 100);
    sfText_setPosition(text, pos);
    sfText_setFont(text, font);
    sfText_setFillColor(text, sfYellow);
    sfText_setOutlineColor(text, sfBlack);
    sfText_setOutlineThickness(text, 4);
    return text;
}

void display_text(game_t game)
{
    char *strgold = my_int_to_strnum(game.gold);

    sfText_setString(game.gold_text, strgold);
    sfRenderWindow_drawText(game.window, game.gold_text, NULL);
}

void game(int level, sfRenderWindow *window, sfEvent event, sfMusic **music)
{
    level_t level_info = level_initialisation(level);
    mobs_t *mobs = mob_initialisation(level_info);
    interface_t interface = interface_initialisation();
    game_t game;
    sfIntRect rect = create_rect(0, 0, 1920, 1080);
    sfVector2f position = create_vect(0, 0);
    sfSprite *map = create_sprite(level_info.bg_filepath, rect, position);
    sfClock *clock = sfClock_create();
    sfTime t;
    tower_t *towers = tower_init(towers);
    spells_t *spell = spell_init();
    int end_game = 0;

    game.window = window;
    game.drag = 0;
    game.drag_spell = 0;
    game.gold = 200;
    game.tower_type = 0;
    game.create = 0;
    interface.emp = level_info.towers;
    game.gold_text = text_init();
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(game.window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(game.window);
        }
        t = sfClock_getElapsedTime(clock);
        if (t.microseconds/1000000.0 > 0.06) {
            mobs = mob_change_rect(mobs);
            spell = spells_effects(spell, &mobs);
            sfClock_restart(clock);
        }
        mobs_move(mobs);
        sfRenderWindow_clear(game.window, sfBlack);
        sfRenderWindow_drawSprite(game.window, map, NULL);
        level_info.gold_earned = 0;
        mobs = mob_man(game.window, mobs, &level_info, &interface.life);
        game.gold += level_info.gold_earned;
        towers = tower_drag(&game, towers, interface.emp);
        spell = spells(interface.spell, spell, &game);
        interface = interface_management(&game, interface);
        display_text(game);
        level_info = change_wave(mobs, level_info);
        pause_button(window, event, music);
        if ((end_game = win_loss_conditions(mobs, interface.life)) != 0)
            break;
        sfRenderWindow_display(game.window);
    }
}
