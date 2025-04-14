/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** Creating my own C Library
*/

#ifndef MY_H_
    #define MY_H_

    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *array, int size);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *str);
char *my_strncat(char *dest, char const *str, int nb);
char *my_strdup(char const *src);
#endif
