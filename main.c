/*
** EPITECH PROJECT, 2020
** 105torus
** File description:
** main.c
*/

#include "include/my.h"

void check_math(double to_check)
{
    if (to_check == 0) {
        printf("Division by zero.\n");
        exit(84);
    }
}

int main(int ac, char **av)
{
    sec_t *sec = malloc(sizeof(sec_t));

    err(ac, av);
    switch (atoi(av[1])){
    case 1 :
        bisection(av);
        break;
    case 2 :
        newton(av);
        break;
    case 3 :
        init_sec(av, sec);
        secant(av, sec);
        break;
    }
    printf("Not launched.\n");
    return (84);
}
