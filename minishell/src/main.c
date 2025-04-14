/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** Recreating minimized terminal
*/

#include "../include/minishell2.h"

int exec_command(char **args, shell_t *shell)
{
    if (!args[0])
        return 1;
    if (check_builtin(args[0]) == 0) {
        return exec_builtin(args, shell);
    }
    return exec_external(args, shell);
}

char **divide_command(char *comm)
{
    char **args = malloc(sizeof(char *) * MAX_ARGS);
    char *tok;
    int i = 0;

    if (!args)
        return (NULL);
    tok = strtok(comm, " \t");
    while (tok && i < MAX_ARGS - 1) {
        args[i] = my_strdup(tok);
        tok = strtok(NULL, " \t");
        i++;
    }
    args[i] = NULL;
    return (args);
}

char *read_command(void)
{
    char *line = NULL;
    size_t size = 0;
    ssize_t x;

    x = getline(&line, &size, stdin);
    if (x == -1) {
        free(line);
        return (NULL);
    }
    if (x > 0 && line[x - 1] == '\n')
        line[x - 1] = '\0';
    return (line);
}

int handle_input(shell_t *shell)
{
    char *line;
    char **args;

    line = read_command();
    if (!line)
        return (-1);
    args = divide_command(line);
    if (args && args[0])
        shell->exit_status = exec_command(args, shell);
    free(line);
    free_array(args);
    return 0;
}

int main(int argc, char **argv, char **env)
{
    shell_t shell;

    (void)argc;
    (void)argv;
    shell.env = copy_env(env);
    shell.exit_status = 0;
    shell.is_running = 1;
    while (shell.is_running) {
        if (isatty(STDIN_FILENO))
            my_putstr("$> ");
        if (handle_input(&shell) == -1)
            break;
    }
    free_array(shell.env);
    return shell.exit_status;
}
