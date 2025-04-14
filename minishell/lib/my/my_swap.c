/*
** EPITECH PROJECT, 2024
** my_swap.c
** File description:
** Swaps the content of two integers whose addresses are given as a parameter
*/

#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

void my_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
