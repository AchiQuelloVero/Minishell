/*
** EPITECH PROJECT, 2024
** my_strncat.c
** File description:
** Concatenate n characters of a a string to the end of the dest string
*/

#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

char *my_strncat(char *dest, char const *str, int nb)
{
    int i;
    int length = my_strlen(dest);

    dest = dest + length;
    for (i = 0; *str && i < nb; i++){
        *dest = *str;
        str++;
        dest++;
    }
    dest++;
    *dest = '\0';
    return dest;
}
