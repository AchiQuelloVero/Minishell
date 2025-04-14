/*
** EPITECH PROJECT, 2024
** my_putstr.c
** File description:
** Displays given string
*/

#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

int my_putstr(char const *str)
{
    int x = 0;

    while (str[x]) {
        my_putchar(str[x]);
    x++;
    }
    return 0;
}
