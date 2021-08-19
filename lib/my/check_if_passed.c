/*
** EPITECH PROJECT, 2020
** check if _depassed
** File description:
** check if mob passed a checkpoint
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>

int check_if_passed(int **cp, int checkpoint, sfVector2f position)
{
    float xcp = cp[0][checkpoint + 1] - cp[0][checkpoint];
    float ycp = cp[1][checkpoint + 1] - cp[1][checkpoint];
    float xmob = cp[0][checkpoint + 1] - position.x;
    float ymob = cp[1][checkpoint + 1] - position.y;
    float norm_cp = (ycp * ycp) + (xcp * xcp);
    float norm_mob = (ymob * ymob) + (xmob * xmob);

    if (norm_cp > norm_mob)
        return 0;
    return 1;
}