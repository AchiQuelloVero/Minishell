/*
** EPITECH PROJECT, 2024
** my_strupcase.c
** File description:
** Every letter becomes upper case
*/

#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

char *my_strupcase(char *str)
{
    for (int b = 0; str[b] != '\0'; b++) {
        if (str[b] >= 'a' && str[b] <= 'z') {
            str[b] = str[b] - 32;
        }
    }
    return str;
}
