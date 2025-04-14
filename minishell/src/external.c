/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** Recreating minimized terminal
*/

#include "../include/minishell2.h"

char *check_comm_path(char *comm, char *path)
{
    char *full_path;
    struct stat st;
    int path_len = my_strlen(path);
    int comm_len = my_strlen(comm);

    full_path = malloc(path_len + comm_len + 2);
    if (!full_path)
        return NULL;
    my_strcpy(full_path, path);
    my_strcat(full_path, "/");
    my_strcat(full_path, comm);
    if (stat(full_path, &st) == 0)
        return my_strdup(full_path);
    free(full_path);
    return NULL;
}

char *get_path_with_env(shell_t *shell)
{
    int i = 0;

    while (shell->env[i] && my_strncmp(shell->env[i], "PATH=", 5))
        i++;
    if (!shell->env[i])
        return NULL;
    return (shell->env[i] + 5);
}

char *search_comm_path(char *comm, shell_t *shell)
{
    char *path;
    char *dir;
    char *comm_path;

    path = get_path_with_env(shell);
    if (!path)
        return NULL;
    dir = strtok(path, ":");
    while (dir) {
        comm_path = check_comm_path(comm, dir);
        if (comm_path)
            return comm_path;
        dir = strtok(NULL, ":");
    }
    return NULL;
}

int handle_comm_path(char **args, shell_t *shell)
{
    char *comm_path;

    if (args[0][0] == '/' || args[0][0] == '.')
        comm_path = my_strdup(args[0]);
    else
        comm_path = search_comm_path(args[0], shell);
    if (!comm_path) {
        my_putstr(args[0]);
        my_putstr(": Command not found.\n");
        exit(84);
    }
    return launch(comm_path, args, shell);
}

int exec_external(char **args, shell_t *shell)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        perror("fork failed");
        return 84;
    }
    if (pid == 0) {
        handle_comm_path(args, shell);
        exit(84);
    }
    waitpid(pid, &status, 0);
    return WEXITSTATUS(status);
}
