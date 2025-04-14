/*
** EPITECH PROJECT, 2024
** my_sort_int_array.c
** File description:
** Sorts array in ascending order
*/

#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

void if_condition(int *array, int i, int temp, int *ordered)
{
    if (array[i] > array[i + 1]) {
            temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
            *ordered = 0;
    }
}

void my_sort_int_array(int *array, int size)
{
    int temp;
    int ordered = 0;

    while (ordered == 0) {
        ordered = 1;
        for (int i = 0; i < size - 1; i++) {
            if_condition(array, i, temp, &ordered);
        }
    }
}
