/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** Recreating minimized terminal
*/

#include "../include/minishell2.h"

int exec_builtin(char **args, shell_t *shell)
{
    if (!my_strcmp(args[0], "cd"))
        return builtin_cd(args, shell);
    if (!my_strcmp(args[0], "env"))
        return builtin_env(args, shell);
    if (!my_strcmp(args[0], "setenv"))
        return builtin_setenv(args, shell);
    if (!my_strcmp(args[0], "unsetenv"))
        return builtin_unsetenv(args, shell);
    if (!my_strcmp(args[0], "exit"))
        return builtin_exit(args, shell);
    return 1;
}

int search_home_path(shell_t *shell)
{
    int i = 0;

    while (shell->env[i]) {
        if (my_strncmp(shell->env[i], "HOME=", 5) == 0)
            return i;
        i++;
    }
    return -1;
}

int builtin_cd(char **args, shell_t *shell)
{
    char *path;
    int home_index;

    if (args[1]) {
        path = args[1];
    } else {
        home_index = search_home_path(shell);
        if (home_index == -1) {
            my_putstr("cd: Home not set\n");
            return 84;
        }
        path = shell->env[home_index] + 5;
    }
    if (chdir(path) == -1) {
        perror("cd");
        return 84;
    }
    return 0;
}

int builtin_env(char **args, shell_t *shell)
{
    int i = 0;

    (void)args;
    while (shell->env[i]) {
        my_putstr(shell->env[i]);
        my_putstr("\n");
        i++;
    }
    return 0;
}

int builtin_setenv(char **args, shell_t *shell)
{
    char **env2;
    int size = 0;

    if (check_setenv_args(args, shell))
        return 84;
    while (shell->env[size])
        size++;
    env2 = duplicate_env(shell, size);
    if (!env2)
        return 84;
    if (!args[2])
        env2[size] = new_env_slot1(args[1]);
    else
        env2[size] = new_env_slot2(args[1], args[2]);
    free(shell->env);
    shell->env = env2;
    return 0;
}
