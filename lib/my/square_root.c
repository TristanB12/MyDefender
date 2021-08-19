/*
** EPITECH PROJECT, 2020
** square root
** File description:
** square root
*/

float square_root(float nb, float min, float max)
{
    float mid = 0;

    if (max - min > 1) {
        mid = (min + max) / 2;
        if (mid * mid > nb)
            square_root(nb, min, mid);
        else {
            square_root(nb, mid, max);
        }
    }
    else {
        return min;
    }
}