/*
** EPITECH PROJECT, 2024
** my_strlowcase.c
** File description:
** Every word becomes lower case
*/

#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

char *my_strlowcase(char *str)
{
    for (int b = 0; str[b] != '\0'; b++) {
        if (str[b] >= 'A' && str[b] <= 'Z') {
            str[b] = str[b] + 32;
        }
    }
    return str;
}
