/*
** EPITECH PROJECT, 2024
** my_strdup
** File description:
** Duplicates a string
*/

#include "../../include/my.h"

char *my_strdup(char const *src)
{
    char *dest;
    int len;

    if (src == NULL)
        return NULL;
    len = my_strlen(src);
    dest = malloc(sizeof(char) * (len + 1));
    if (dest == NULL)
        return NULL;
    my_strcpy(dest, src);
    return dest;
}
