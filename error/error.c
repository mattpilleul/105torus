/*
** EPITECH PROJECT, 2020
** 105torus
** File description:
** error.c
*/

#include "../include/my.h"

void disp_h(void)
{
    printf("USAGE\n   ./105torus opt a0 a1 a2 a3 a4 n\n\nDESCRIPTION\n   ");
    printf("opt       method option:\n                 1 for the bisection ");
    printf("method\n                 2 for the Newton's method\n             \
    3 for the secant method\n   a[0-4]    coefficient of the equation\n");
    printf("   n         precision (the application of the polynomial to the");
    printf(" solution should be smaller than 10^-n)\n");
    exit(0);
}

void err2(int ac, char **av)
{
    for (int i = 2; i < 7; i++) {
        if ((av[i][0] < '0' || av[i][0] > '9') && av[i][0] != '-') {
            printf("Argument %i: not a number.\n", i);
            exit(84);
        } else if ((av[i][0] < '0' || av[i][0] > '9') && av[i][0] == '-' \
        && strlen(av[i]) == 1) {
            printf("Argument %i: not a number.\n", i);
            exit(84);
        }
        for (int j = 1; j < strlen(av[i]); j++) {
            if (av[i][j] < '0' || av[i][j] > '9') {
                printf("Argument %i: not a number.\n", i);
                exit(84);
            }
        }
    }
}

void err3(char **av)
{
    for (int i = 0; i < strlen(av[7]); i++)
        if (av[7][i] < '0' || av[1][i] > '9') {
            printf("Precision is wrong, it should be a positive integer.\n");
            exit(84);
        }
    if (atoi(av[7]) <= 0) {
        printf("Precision is wrong; it should be a positive integer.\n");
        exit(84);
    }
    if (atoi(av[2]) == 0) {
        printf("a0 should be different from zero\n");
        exit(84);
    }
}

void err4(int ac)
{
    printf("Not enought arguments.\n");
    exit(84);
}

void err(int ac, char **av)
{
    if (ac == 1){
        printf("No argument given, retry with -h.\n");
        exit(84);
    }
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
        disp_h();
    if (ac < 8){
	err4(ac);
    }
    if (ac > 8){
        printf("Too many arguments.\n");
        exit(84);
    }
    if (av[1][0] <= '0' || av[1][0] >= '4' || atoi(av[1]) > 3 || \
    atoi(av[1]) < 0 || strlen(av[1]) != 1){
        printf("Option is wrong: it's different from either 1, 2 or 3.\n");
        exit(84);
    }
    err2(ac, av);
    err3(av);
}
