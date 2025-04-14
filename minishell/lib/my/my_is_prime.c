/*
** EPITECH PROJECT, 2024
** my_is_prime.c
** File description:
** Returns 1 if the number is prime and 0 if it's not
*/

#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

int my_is_prime(int nb)
{
    if (nb <= 0 || nb == 1) {
        return 0;
    }
    if (nb % 2 == 0 && nb > 2) {
        return 0;
    }
    for (int i = 3; i <= nb / 2; i = i + 2) {
        if (nb % i == 0) {
            return 0;
        }
    }
    return 1;
}
