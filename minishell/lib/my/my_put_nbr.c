/*
** EPITECH PROJECT, 2024
** my_put_nbr.c
** File description:
** Displays nb as number
*/

#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

int my_put_nbr(int nb)
{
    if (nb == -2147483648){
        my_putchar('-');
        my_putchar('2');
        my_put_nbr(14783648);
        return 0;
    }
    if (nb <= -1){
        nb = nb * -1;
        my_putchar(45);
    }
    if (nb > 9){
        my_put_nbr(nb / 10);
    }
    my_putchar(nb % 10 + '0');
    return 0;
}
