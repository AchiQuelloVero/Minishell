/*
** EPITECH PROJECT, 2024
** my_find_prime_sup.c
** File description:
** Returns the smallest prime number greater or equal to nb
*/

#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

int my_find_prime_sup(int nb)
{
    if (nb <= 1) {
        return 2;
    }
    while (!my_is_prime(nb)) {
        nb++;
    }
    return nb;
}
