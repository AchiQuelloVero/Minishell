/*
** EPITECH PROJECT, 2024
** my_strstr.c
** File description:
** Creating my own C Library
*/

#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

char *my_strstr(char *str, char const *to_find)
{
    int b = 0;
    int c = 0;

    while (str[b] != '\0') {
        if (str[b] == to_find[c]) {
            c++;
            b++;
        } else {
            c = 0;
            b++;
        }
        if (to_find[c] == '\0') {
            return (&str[b - c]);
        }
    }
    return (NULL);
}
