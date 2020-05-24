/*
** EPITECH PROJECT, 2020
** 105torus
** File description:
** newton.c
*/

#include "../include/my.h"

void init_newt(newt_t *newt, char **av)
{
    newt->a0 = atoi(av[2]);
    newt->a1 = atoi(av[3]);
    newt->a2 = atoi(av[4]);
    newt->a3 = atoi(av[5]);
    newt->a4 = atoi(av[6]);
    newt->n = atoi(av[7]);
}

void newton(char **av)
{
    newt_t *newt = malloc(sizeof(newt_t));
    double x = 0.5;
    double fx;

    init_newt(newt, av);
    fx = newt->a4 * pow(x, 4) + newt->a3 * pow(x, 3) + newt->a2 * \
    pow(x, 2) + newt->a1 * x + newt->a0;
    while (fabs(fx) >= pow(10, -newt->n)) {
        printf("x = %.*f\n", check_pres(x, atoi(av[7])), x);
        check_math((4 * newt->a4 * pow(x, 3) + 3 * newt->a3 * pow(x, 2) \
        + 2 * newt->a2 * x + newt->a1));
        x -= fx / (4 * newt->a4 * pow(x, 3) + 3 * newt->a3 * pow(x, 2) \
        + 2 * newt->a2 * x + newt->a1);
        fx = newt->a4 * pow(x, 4) + newt->a3 * pow(x, 3) + newt->a2 * \
        pow(x, 2) + newt->a1 * x + newt->a0;
        if (x > 1 || x < 0) {
            printf("Diverging\n");
            exit(84);
        }
    }
    printf("x = %.*f\n", check_pres(x, atoi(av[7])), x);
    exit(0);
}
