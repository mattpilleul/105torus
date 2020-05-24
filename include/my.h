/*
** EPITECH PROJECT, 2019
** 105torus
** File description:
** my.h
*/

#ifndef MY_H
#define MY_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct bisec {
    double left;
    double right;
    double result;
    double a;
    double b;
    double c;
}bisec_t;

typedef struct newt {
    double a0;
    double a1;
    double a2;
    double a3;
    double a4;
    double n;
}newt_t;

typedef struct sec {
    double max;
    double a0;
    double a1;
    double a2;
    double a3;
    double a4;
    double xmem;
    double n;
    double x0;
    double x1;
    double fx0;
    double fx1;
}sec_t;

void err(int ac, char **av);
void bisection(char **av);
int check_number(char **argv);
int get_digit(double nb, int digit);
int check_pres(double nb, int max);
int print_help(void);
void newton(char **av);
void secant(char **av, sec_t *sec);
sec_t init_sec(char **av, sec_t *sec);
void check_math(double to_check);

#endif
