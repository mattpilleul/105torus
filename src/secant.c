/*
** EPITECH PROJECT, 2020
** 105torus
** File description:
** bisection.c
*/

#include "../include/my.h"

sec_t init_sec(char **av, sec_t *sec)
{
    sec->a0 = atoi(av[2]);
    sec->a1 = atoi(av[3]);
    sec->a2 = atoi(av[4]);
    sec->a3 = atoi(av[5]);
    sec->a4 = atoi(av[6]);
    sec->n = atoi(av[7]);
    sec->x0 = 0;
    sec->x1 = 1;
    sec->fx0 = sec->a4 * pow(sec->x0, 4) + sec->a3 * pow(sec->x0, 3) \
    + sec->a2 * pow(sec->x0, 2) + sec->a1 * sec->x0 + sec->a0;
    sec->fx1 = sec->a4 * pow(sec->x1, 4) + sec->a3 * pow(sec->x1, 3) \
    + sec->a2 * pow(sec->x1, 2) + sec->a1 * sec->x1 + sec->a0;
}

void secant(char **av, sec_t *sec)
{
    for (sec->max = 0; fabs(sec->fx1) >= pow(10, -sec->n) && sec->max < 100; \
    sec->max++){
        sec->xmem = sec->x1;
        check_math(sec->fx1 - sec->fx0);
        sec->x1 = sec->x1 - ((sec->x1 - sec->x0) / (sec->fx1 - sec->fx0)) * \
        sec->fx1;
        sec->x0 = sec->xmem;
        sec->fx0 = sec->fx1;
        sec->fx1 = sec->a4 * pow(sec->x1, 4) + sec->a3 * pow(sec->x1, 3) \
        + sec->a2 * pow(sec->x1, 2) + sec->a1 * sec->x1 + sec->a0;
        printf("x = %.*f\n", check_pres(sec->x1, atoi(av[7])), sec->x1);
        if (sec->x1 > 1 || sec->x1 < 0){
            printf("Diverging\n");
            exit(84);
        }
    }
    if (sec->max == 99){
        exit(84);
    }
    exit(0);
}
