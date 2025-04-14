/*
** EPITECH PROJECT, 2024
** my_putchar.c
** File description:
** Print one character
*/

#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
