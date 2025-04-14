/*
** EPITECH PROJECT, 2024
** my_strncpy.c
** File description:
** Copies string into another string
*/

#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int x = 0;

    while (x < n && src[x] != '\0') {
        dest[x] = src[x];
        x++;
    }
    while (x < n) {
        dest[x] = '\0';
        x++;
    }
    return dest;
}
