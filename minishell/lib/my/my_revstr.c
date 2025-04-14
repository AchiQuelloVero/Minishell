/*
** EPITECH PROJECT, 2024
** my_revstr.c
** File description:
** Swaps each string's character and returns it
*/

#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

char *my_revstr(char *str)
{
    int l = 0;
    char t;

    while (str[l] != '\0') {
        l++;
    }
    for (int x = 0; x < l / 2; x++) {
        t = str[x];
        str[x] = str[l - 1 - x];
        str[l - 1 - x] = t;
    }
    return str;
}
