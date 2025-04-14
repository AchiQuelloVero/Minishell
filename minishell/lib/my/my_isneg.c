/*
** EPITECH PROJECT, 2024
** my_isneg.c
** File description:
** Displays N if nb negative and P if positive
*/

#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

int my_isneg(int nb)
{
    if (nb >= 0) {
        my_putchar(80);
    } else {
        my_putchar(78);
    }
    return 0;
}
