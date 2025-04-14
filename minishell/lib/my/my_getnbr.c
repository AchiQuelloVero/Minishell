/*
** EPITECH PROJECT, 2024
** my_getnbr.c
** File description:
** Returns a number sent to the function as string
*/

#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

int my_getneg(char const *str)
{
    int i = 0;
    int nb = 1;

    while (str[i] < '0' || str[i] > '9') {
        if (str[i] == '-')
            nb = nb * (-1);
        i++;
    }
    return (nb);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int nb = 0;

    while (str[i] != '\0' && str[i] != '\n') {
        if (str[i] < '0' || str[i] > '9')
            return (-1);
        i++;
    }
    i = 0;
    while (str[i] >= '0' && str[i] <= '9') {
        nb = ((nb * 10) + (str[i] - 48));
        i++;
    }
    nb = nb * my_getneg(str);
    return (nb);
}
