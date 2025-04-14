/*
** EPITECH PROJECT, 2024
** functions02.c
** File description:
** Calculates length of a string
*/

#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

int my_strlen(char const *str)
{
    int x = 0;

    while (*str != '\0') {
        x = x + 1;
        str = str + 1;
    }
    return x;
}
