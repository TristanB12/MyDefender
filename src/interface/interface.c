/*
** EPITECH PROJECT, 2020
** inter
** File description:
** function of in game inter
*/

#include "interface.h"
#include "tower.h"

icons_towers_t tower_hover(interface_t *inter, game_t *g, int i)
{
    sfVector2f pos = sfSprite_getPosition(inter[0].tower[i].sprite);
    sfVector2i mouse_pos = sfMouse_getPosition((sfWindow*)g[0].window);
    sfIntRect rect;

    if (mouse_pos.x > pos.x && mouse_pos.x < (pos.x + 150) &&
        mouse_pos.y > pos.y && mouse_pos.y < (pos.y + 150)) {
        rect = sfSprite_getTextureRect(inter[0].tower[i].sprite);
        rect.top = 150;
        sfSprite_setTextureRect(inter[0].tower[i].sprite, rect);
        g[0].create = 0;
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue && g[0].drag == 0) {
            g[0].create = 1;
            g[0].tower_type = inter[0].tower[i].type;
        }
    }
    else {
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfFalse && g[0].drag == 1)
            g[0].drag = 2;
        rect = sfSprite_getTextureRect(inter[0].tower[i].sprite);
        rect.top = 0;
        sfSprite_setTextureRect(inter[0].tower[i].sprite, rect);
    }
    return inter[0].tower[i];
}

icons_spells_t spell_hover(icons_spells_t tower, game_t game)
{
    sfVector2f pos = sfSprite_getPosition(tower.sprite);
    sfVector2i mouse_pos = sfMouse_getPosition((sfWindow*)game.window);
    sfIntRect rect;

    if (mouse_pos.x > pos.x && mouse_pos.x < (pos.x + 150) &&
        mouse_pos.y > pos.y && mouse_pos.y < (pos.y + 150)) {
        rect = sfSprite_getTextureRect(tower.sprite);
        rect.top = 150;
        sfSprite_setTextureRect(tower.sprite, rect);
    }
    else {
        rect = sfSprite_getTextureRect(tower.sprite);
        rect.top = 0;
        sfSprite_setTextureRect(tower.sprite, rect);
    }
    return tower;
}

tower_emp_t emp_hover(tower_emp_t tower, game_t game)
{
    sfVector2f pos = sfSprite_getPosition(tower.sprite);
    sfVector2i mouse_pos = sfMouse_getPosition((sfWindow*)game.window);
    sfIntRect rect;

    if (mouse_pos.x > pos.x && mouse_pos.x < (pos.x + 50) &&
        mouse_pos.y > pos.y && mouse_pos.y < (pos.y + 75)) {
        rect = sfSprite_getTextureRect(tower.sprite);
        rect.left = 50;
        sfSprite_setTextureRect(tower.sprite, rect);
    }
    else {
        rect = sfSprite_getTextureRect(tower.sprite);
        rect.left = 0;
        sfSprite_setTextureRect(tower.sprite, rect);
    }
    return tower;
}

castle_life_t castle_life_management(castle_life_t life, sfRenderWindow *window)
{
    sfIntRect rect_life = sfSprite_getTextureRect(life.life_bar);

    rect_life.width = life.life * 4;
    sfSprite_setTextureRect(life.life_bar, rect_life);
    sfRenderWindow_drawSprite(window, life.bg, NULL);
    sfRenderWindow_drawSprite(window, life.life_bar, NULL);
    return life;
}

interface_t interface_management(game_t *g, interface_t inter)
{
    int j = 0, k = 0, i = 0, a = inter.emp[0].nb_emp;

    while (i < 4) {
        inter.tower[i] = tower_hover(&inter, g, i);
        sfRenderWindow_drawSprite(g[0].window, inter.tower[i].sprite, NULL);
        i++;
    }
    while (j < 3) {
        inter.spell[j] = spell_hover(inter.spell[j], g[0]);
        sfRenderWindow_drawSprite(g[0].window, inter.spell[j].sprite, NULL);
        j++;
    }
    while (k < a) {
        inter.emp[k] = emp_hover(inter.emp[k], g[0]);
        if (inter.emp[k].taken == 0)
            sfRenderWindow_drawSprite(g[0].window, inter.emp[k].sprite, NULL);
        k++;
    }
    inter.life = castle_life_management(inter.life, g[0].window);
    return inter;
}