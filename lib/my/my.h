/*
** EPITECH PROJECT, 2019
** C Pool InfinAdd
** File description:
** Header file for libmy
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

#ifndef __DEF_MY__
#define __DEF_MY__

    void my_putchar(char my_char);
    int my_putstr(char const *str);
    int my_is_digit(char const my_char);
    int is_left_paren(char const my_char);
    int is_right_paren(char const my_char);
    int is_paren(char const my_char);
    int my_str_isnum(char const *str);
    int my_strcmp(char const *s1, char const *s2);
    int my_get_denominator(int const nb);
    int my_intlen(int nb);
    int my_strlen(char const *str);
    int my_strlen_ns(char const *str);
    int my_put_nbr(int nb);
    int my_strnum_to_int(char *str);
    sfSprite *create_sprite(char *path, sfIntRect rect, sfVector2f position);
    char *my_strdup_ns(char const *str);
    char *my_int_to_strnum(int nb);
    sfIntRect create_rect(int l, int t, int w, int h);
    sfVector2f create_vect(float x, float y);
    sfVector2f calcul_vect(sfVector2f position, int **cp, int pos_point);
    int check_if_passed(int **cp, int checkpoint, sfVector2f position);
    float square_root(float nb, float min, float max);
    int my_get_denominator(int const nb);
    int my_intlen(int nb);
char *my_int_to_strnum(int nb);
void game(int level, sfRenderWindow *window, sfEvent event, sfMusic **music);
#endif
