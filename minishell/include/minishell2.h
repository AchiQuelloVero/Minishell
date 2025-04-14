/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** minishell2
*/

#ifndef MINISHELL2_H_
    #define MINISHELL2_H_

    #include "my.h"
    #include <sys/wait.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <dirent.h>
    #include <string.h>

    #define MAX_ARGS 32

typedef struct shell {
    char **env;
    int is_running;
    int exit_status;
} shell_t;

// main.c
int handle_input(shell_t *shell);
char *read_command(void);
char **divide_command(char *comm);
int exec_command(char **args, shell_t *shell);

// external.c
int exec_external(char **args, shell_t *shell);
int handle_comm_path(char **args, shell_t *shell);
char *search_comm_path(char *comm, shell_t *shell);
char *get_path_with_env(shell_t *shell);
char *check_comm_path(char *comm, char *path);

// builtin.c & builtin2.c & builtin3.c
int exec_builtin(char **args, shell_t *shell);

int search_home_path(shell_t *shell);
int builtin_cd(char **args, shell_t *shell);

int builtin_env(char **args, shell_t *shell);

char *new_env_slot2(char *name, char *value);
char *new_env_slot1(char *name);
char **duplicate_env(shell_t *shell, int size);
int is_alphanumeric(const char *str);
int check_setenv_args(char **args, shell_t *shell);
int builtin_setenv(char **args, shell_t *shell);

void reset_env(shell_t *shell, int i);
int builtin_unsetenv(char **args, shell_t *shell);

int get_ext_status(char *arg1);
int builtin_exit(char **args, shell_t *shell);

// utils.c
char **copy_env(char **env);
int count_env(char **env);
void free_array(char **env);
int check_builtin(char *comm);
int launch(char *comm_path, char **args, shell_t *shell);
#endif
