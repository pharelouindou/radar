/*
** EPITECH PROJECT, 2024
** add
** File description:
** add
*/

#include "dad.h"

void execute1(char **args, char **env, char *exec_path)
{
    int child_pid = fork();
    int status;

    if (child_pid < 0) {
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        dex(args, env, exec_path);
    } else {
        waitpid(child_pid, &status, 0);
        check_sign(status);
    }
}

char *create_exec_path(char *path, char *arg)
{
    char *exec_path = malloc(my_strlen(path) + my_strlen(arg) + 2);

    if (exec_path == NULL) {
        exit(EXIT_FAILURE);
    }
    my_strcpy(exec_path, path);
    my_strcat(exec_path, "/");
    my_strcat(exec_path, arg);
    return exec_path;
}

void verifer(char *exec_path)
{
    struct stat sb;

    if (S_ISDIR(sb.st_mode)) {
        my_printf("%s: Permission denied.\n", exec_path);
        free(exec_path);
        exec_path = NULL;
    } else if (access(exec_path, X_OK) == -1) {
        my_printf("%s: Permission denied.\n", exec_path);
        free(exec_path);
        exec_path = NULL;
    }
}

void gang(char *exec_path)
{
    struct stat sb;

    if (stat(exec_path, &sb) == 0) {
        verifer(exec_path);
    } else {
        free(exec_path);
        exec_path = NULL;
    }
}

char *check_exec_path(char *exec_path, char *arg)
{
    if (exec_path == NULL) {
        my_printf("%s: Command not found.\n", arg);
    } else {
        gang(exec_path);
    }
    return exec_path;
}
