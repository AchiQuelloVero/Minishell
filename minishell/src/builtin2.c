/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** Recreating minimized terminal
*/

#include "../include/minishell2.h"

char *new_env_slot2(char *name, char *value)
{
    char *new_slot;
    int len = my_strlen(name) + my_strlen(value) + 2;

    new_slot = malloc(len);
    if (!new_slot)
        return NULL;
    my_strcpy(new_slot, name);
    my_strcat(new_slot, "=");
    my_strcat(new_slot, value);
    return new_slot;
}

char *new_env_slot1(char *name)
{
    char *new_slot;
    int len = my_strlen(name) + 2;

    new_slot = malloc(len);
    if (!new_slot)
        return NULL;
    my_strcpy(new_slot, name);
    my_strcat(new_slot, "=");
    return new_slot;
}

char **duplicate_env(shell_t *shell, int size)
{
    char **env2;
    int i = 0;

    env2 = malloc(sizeof(char *) * (size + 2));
    if (!env2)
        return NULL;
    while (shell->env[i]) {
        env2[i] = shell->env[i];
        i++;
    }
    env2[i + 1] = NULL;
    return env2;
}

int check_setenv_args(char **args, shell_t *shell)
{
    if (!args[1]) {
        builtin_env(args, shell);
        return 1;
    }
    if (args[3]) {
        my_putstr("setenv: Too many arguments.\n");
        return 1;
    }
    if (!is_alphanumeric(args[1])) {
        my_putstr(
            "setenv: Variable name must contain alphanumeric characters.\n");
        return 1;
    }
    return 0;
}

int builtin_unsetenv(char **args, shell_t *shell)
{
    int i = 0;
    int len;

    if (!args[1]) {
        my_putstr("unsetenv: Too few arguments.\n");
        return 84;
    }
    len = my_strlen(args[1]);
    while (shell->env[i]) {
        if (!my_strncmp(shell->env[i], args[1], len)
        && shell->env[i][len] == '=') {
            free(shell->env[i]);
            reset_env(shell, i);
            return 1;
        }
        i++;
    }
    return 0;
}
