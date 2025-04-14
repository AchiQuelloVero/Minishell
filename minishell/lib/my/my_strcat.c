/*
** EPITECH PROJECT, 2024
** my_strcat.c
** File description:
** Concatenate two strings
*/

#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

char *my_strcat(char *dest, char const *str)
{
    int length = my_strlen(dest);

    dest = dest + length;
    while (*str){
        *dest = *str;
        str++;
        dest++;
    }
    dest++;
    *dest = '\0';
    return dest;
}
