/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** Recreating minimized terminal
*/

#include "../include/minishell2.h"

int count_env(char **env)
{
    int i = 0;

    while (env[i])
        i++;
    return i;
}

char **copy_env(char **env)
{
    int size = count_env(env);
    char **env2 = malloc(sizeof(char *) * (size + 1));
    int i = 0;

    if (!env2)
        return NULL;
    while (env[i]) {
        env2[i] = my_strdup(env[i]);
        i++;
    }
    env2[i] = NULL;
    return env2;
}

void free_array(char **array)
{
    int i = 0;

    if (!array)
        return;
    while (array[i]) {
        free(array[i]);
        i++;
    }
    free(array);
}

int check_builtin(char *comm)
{
    if (my_strcmp(comm, "cd") == 0 || my_strcmp(comm, "env") == 0 ||
    my_strcmp(comm, "setenv") == 0 || my_strcmp(comm, "unsetenv") == 0 ||
    my_strcmp(comm, "exit") == 0) {
        return 0;
    }
    return -1;
}

int launch(char *comm_path, char **args, shell_t *shell)
{
    if (execve(comm_path, args, shell->env) == -1) {
        perror("execve");
    }
    free(comm_path);
    exit(84);
}
