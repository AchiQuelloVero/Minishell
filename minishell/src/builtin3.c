/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** Recreating minimized terminal
*/

#include "../include/minishell2.h"

int is_alphanumeric(const char *str)
{
    int i = 0;

    while (str[i]) {
        if (!((str[i] >= 'a' && str[i] <= 'z') ||
            (str[i] >= 'A' && str[i] <= 'Z') ||
            (str[i] >= '0' && str[i] <= '9'))) {
            return 0;
        }
        i++;
    }
    return 1;
}

void reset_env(shell_t *shell, int i)
{
    int pos = i;

    while (shell->env[pos]) {
        shell->env[pos] = shell->env[pos + 1];
        pos++;
    }
}

int get_ext_status(char *arg1)
{
    int i = 0;
    int ext_status = 0;

    while (arg1[i] >= '0' && arg1[i] <= '9') {
        ext_status = ext_status * 10 + (arg1[i] - '0');
        i++;
    }
    return ext_status;
}

int builtin_exit(char **args, shell_t *shell)
{
    shell->is_running = 0;
    if (!args[1])
        return 0;
    shell->exit_status = get_ext_status(args[1]);
    return 0;
}
