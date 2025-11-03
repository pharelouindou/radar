/*
** EPITECH PROJECT, 2024
** add
** File description:
** add
*/

#include "dad.h"

void add_old(t_env *envi)
{
    char path[1024];
    char **pg;

    getcwd(path, 1024);
    pg = malloc(sizeof(char *) * 4);
    pg[0] = my_strdup("");
    pg[1] = my_strdup("OLDPWD");
    pg[2] = my_strdup(path);
    pg[3] = NULL;
    my_setenv(envi, pg);
    free(pg[0]);
    free(pg[1]);
    free(pg[2]);
    free(pg);
}

char *find_exec_path(char **args, char **env)
{
    int path_index = find_variable_index("PATH", env);
    char **paths = my_str_to_word_array(env[path_index] + 5, ':');
    char *exec_path = NULL;

    if (path_index == -1 || paths == NULL) {
        return NULL;
    }
    for (int i = 0; paths[i] != NULL; i++) {
        exec_path = create_exec_path(paths[i], args[0]);
        if (access(exec_path, X_OK) == 0) {
            break;
        }
        free(exec_path);
        exec_path = NULL;
    }
    exec_path = check_exec_path(exec_path, args[0]);
    free_word_array(paths);
    return exec_path;
}

void execute(char **args, char **env)
{
    char *exec_path = NULL;

    if (my_strlen(args[0]) > 5 && my_strncmp(args[0], "/bin/", 5) == 0) {
        exec_path = args[0];
    } else {
        exec_path = find_exec_path(args, env);
    }
    if (exec_path != NULL) {
        execute1(args, env, exec_path);
        free(exec_path);
    }
}
