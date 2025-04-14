/*
** EPITECH PROJECT, 2024
** my_strcpy.c
** File description:
** Copies string into another string
*/

#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

char *my_strcpy(char *dest, char const *src)
{
    int b = 0;

    while (src[b] != '\0') {
        dest[b] = src[b];
        b++;
    }
    dest[b] = '\0';
    return dest;
}
