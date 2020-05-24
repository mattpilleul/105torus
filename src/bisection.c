/*
** EPITECH PROJECT, 2020
** 105torus
** File description:
** bisection.c
*/

#include "../include/my.h"

int check_pres(double nb, int max)
{
    int size = 15;

    while (get_digit(nb, size) == 0){
        size--;
    }
    if (size > max)
        size = max;
    return (size);
}

int get_digit(double nb, int digit)
{
    int n = 0;

    nb *= pow(10, digit);
    while (nb > 9 && n < digit){
        nb = fmod(nb, pow(10, digit - n));
	n++;
    }
    return (nb);
}

bisec_t init_bisec(bisec_t *bisec, char **av)
{
    bisec->left = 0;
    bisec->right = 1;
    bisec->result = (bisec->left + bisec->right) / 2;
    bisec->a = (atof(av[6]) * pow(bisec->left, 4)) + (atof(av[5]) *	\
    pow(bisec->left, 3)) + (atof(av[4]) * pow(bisec->left, 2)) + \
    (atof(av[3]) * bisec->left) + atof(av[2]);
    bisec->b = (atof(av[6]) * pow(bisec->right, 4)) + (atof(av[5]) * \
    pow(bisec->right, 3)) + (atof(av[4]) * pow(bisec->right, 2)) + \
    (atof(av[3]) * bisec->right) + atof(av[2]);
    bisec->c = (atof(av[6]) * pow(bisec->result, 4)) + \
    (atof(av[5]) * pow(bisec->result, 3)) + (atof(av[4]) * \
    pow(bisec->result, 2)) + (atof(av[3]) * bisec->result) + atof(av[2]);
}

void bisection2(bisec_t *bisec, char **av)
{
    bisec->result = (bisec->left + bisec->right) / 2;
    bisec->a = (atof(av[6]) * pow(bisec->left, 4)) + (atof(av[5]) * \
    pow(bisec->left, 3)) + \
    (atof(av[4]) * pow(bisec->left, 2)) + (atof(av[3]) * bisec->left) + \
    atof(av[2]);
    bisec->b = (atof(av[6]) * pow(bisec->right, 4)) + (atof(av[5]) * \
    pow(bisec->right, 3)) + \
    (atof(av[4]) * pow(bisec->right, 2)) + (atof(av[3]) * bisec->right) + \
    atof(av[2]);
    bisec->c = (atof(av[6]) * pow(bisec->result, 4)) + \
    (atof(av[5]) * pow(bisec->result, 3)) + (atof(av[4]) * \
    pow(bisec->result, 2)) + \
    (atof(av[3]) * bisec->result) + atof(av[2]);
}

void bisection(char **av)
{
    bisec_t *bisec = malloc(sizeof(bisec_t));
    init_bisec(bisec, av);
    int i = -1;
    double n = pow(10, -(atof(av[7])));

    if (fabs(bisec->c) < n)
        printf("x = %.*f\n", check_pres(bisec->result, atoi(av[7])), \
        bisec->result);
    while (fabs(bisec->c) > n && i++ < 50){
        bisection2(bisec, av);
        if ((bisec->a * bisec->c) < 0)
            bisec->right = bisec->result;
        else
            bisec->left = bisec->result;
        if (bisec->result > 1 || bisec->result < 0){
            printf("Diverging\n");
            exit(84);
        }
        printf("x = %.*f\n", check_pres(bisec->result, atoi(av[7])), \
        bisec->result);
    }
    exit(0);
}
