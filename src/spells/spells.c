/*
** EPITECH PROJECT, 2020
** spells
** File description:
** spells function
*/
#include "struct.h"
#include "interface.h"
#include "spells.h"

spells_t *spell_display(spells_t *spells, sfRenderWindow *window)
{
    sfVector2f spell_pos;
    sfIntRect spell_rect;
    sfVector2i mouse_pos = sfMouse_getPosition((sfWindow *) window);

    for (int i = 0; i < 3; i++) {
        if (spells[i].active == 1) {
            spell_rect = sfSprite_getTextureRect(spells[i].sprite);
            spell_pos.x = mouse_pos.x - spell_rect.width / 2;
            spell_pos.y = mouse_pos.y - spell_rect.height / 2;
            sfSprite_setPosition(spells[i].sprite, spell_pos);
        }
        sfRenderWindow_drawSprite(window, spells[i].sprite, NULL);
    }
    return spells;
}

int spell_can_be_droped(icons_spells_t *emp, sfRenderWindow *window)
{
    sfVector2i mouse_pos = sfMouse_getPosition((sfWindow *) window);
    sfVector2f emp_pos;

    for (int i = 0; i < 3; i++) {
        emp_pos = sfSprite_getPosition(emp[i].sprite);
        if (mouse_pos.x > emp_pos.x && mouse_pos.x < emp_pos.x + 150 &&
            mouse_pos.y > emp_pos.y && mouse_pos.y < emp_pos.y + 150)
            return 0;
    }
    return 1;
}

spells_t *spell_drop(spells_t *spells, game_t *game, icons_spells_t *emp)
{
    sfVector2f initial_pos = {4000, 0};

    for (int i = 0; i < 3; i++) {
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfFalse &&
            spells[i].active == 1) {
            if (spell_can_be_droped(emp, game[0].window) == 1)
                spells[i].active = 2;
            else {
                spells[i].active = 0;
                sfSprite_setPosition(spells[i].sprite, initial_pos);
            }
            game[0].drag_spell = 0;
        }
    }
    return spells;
}

spells_t *spells(icons_spells_t *interface_spells, spells_t *spells, game_t *g)
{
    sfVector2i mouse_pos = sfMouse_getPosition((sfWindow *) g[0].window);
    sfVector2f pos;
    sfIntRect rect;

    for (int i = 0; i < 3; i++) {
        pos = sfSprite_getPosition(interface_spells[i].sprite);
        if (mouse_pos.x > pos.x && mouse_pos.x < pos.x + 150 &&
            mouse_pos.y > pos.y && mouse_pos.y < pos.y + 150 &&
            sfMouse_isButtonPressed(sfMouseLeft) && g[0].drag_spell == 0) {
            g[0].drag_spell = 1;
            spells[interface_spells[i].type].active = 1;
            if (spells[i].active == 1) {
                rect = sfSprite_getTextureRect(spells[i].sprite);
                rect.left = 0;
                sfSprite_setTextureRect(spells[i].sprite, rect);
            }
        }
    }
    spells = spell_drop(spells, g, interface_spells);
    spells = spell_display(spells, g[0].window);
    return spells;
}