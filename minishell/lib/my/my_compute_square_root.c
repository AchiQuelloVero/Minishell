/*
** EPITECH PROJECT, 2024
** my_compute_square_root.c
** File description:
** Returns square root of nb
*/

#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

int my_compute_square_root(int nb)
{
    for (int i = 0; i * i <= nb; i++) {
        if (i * i == nb) {
            return i;
        }
    }
    return 0;
}
