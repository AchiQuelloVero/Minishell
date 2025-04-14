/*
** EPITECH PROJECT, 2024
** my_strcapitalize.c
** File description:
** Puts first letter of each word in upper case
*/

#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

char *my_lowcase1(char *str)
{
    while (*str) {
        if (*str >= 65 && *str <= 90) {
            *str = *str + 32;
        }
        str++;
    }
    return 0;
}

void set_upcase(char *str)
{
    *str = *str - 32;
}

void check_before(char *str)
{
    char *cB = str - 1;

    if (*cB < 97 || *cB > 122){
        if ((*cB < 65 || *cB > 90) && (*cB < 48 || *cB > 57)){
            set_upcase(str);
        }
    } else {
        return;
    }
}

void check_letters(char *str)
{
    if (*str >= 97 && *str <= 122){
        check_before(str);
    } else {
        return;
    }
}

char *my_strcapitalize(char *str)
{
    int i;

    my_lowcase1(str);
    for (i = 0; *str; i++){
        check_letters(str);
        str++;
    }
    return str;
}
