/*
** EPITECH PROJECT, 2024
** my_strncmp.c
** File description:
** Creating my own C Library
*/

#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int b = 0;

    while (b < n) {
        if (s1[b] != s2[b] || s1[b] == '\0' || s2[b] == '\0') {
            return (s1[b] - s2[b]);
        }
        b++;
    }
    return 0;
}
