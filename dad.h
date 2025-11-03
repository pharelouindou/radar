/*
** EPITECH PROJECT, 2023
** mon h
** File description:
** my
*/

#ifndef PH
    #define PH

    #include <stdarg.h>
    #include <math.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <stdbool.h>
    #include <sys/wait.h>
    #include <sys/stat.h>
    #include <signal.h>
typedef struct s_env {
    char *elem;
    struct s_env *nxt;
} t_env;
int delete_list(t_env **env, char *name);
void add_end_list(t_env **env, char *str);
void my_env(t_env *env);
void my_setenv(t_env *env, char **exe);
void my_unsetenv(t_env *env, char **exe);
void execute(char **args, char **env);
char *my_strcpy(char *dest, const char *src);
char *my_strdup(char *src);
char *my_strcat(char *dest, char *src);
void handle_builtin(char **args, char **env, t_env *envi);
char **my_str_to_word_array(char *str, char delimiter);
int find_variable_index(char *variable, char **env);
bool check_error(char **arg);
void my_cd(char **env, const char *path);
void my_putchar(char c);

int my_put_nbr(int nb);

int my_putstr(char const *str);

void printf_str(va_list ap);

int my_printf(const char *format, ...);

void change(const char *format, int *i, va_list ap);

void printf_int(va_list ap);

void printf_char(va_list ap);

int base(int);

void prinf_li(va_list ap);

void printf_hi(va_list ap);

void printf_fl(va_list ap);

void printf_hex(va_list ap);

void cas_p(const char *format, int *i, va_list ap);

void cas(const char *format, int *i, va_list ap);

int octal(int b);

void printf_hex2(va_list ap);

int hexx(int b);

void printf_oct(va_list ap);

void reduce(double f);

void reduce2(double f);

void printf_unsigned_int(va_list ap);

void printf_e(va_list ap);

int my_strlen(char *str);

void expo(int exponent);

void cas_pls(const char *format, int *i, va_list ap);

int my_put_nbr_u(unsigned int nb);

int bin(int nb);

void printf_bin(va_list ap);
void execute1(char **args, char **env, char *exec_path);
char *check_exec_path(char *exec_path, char *arg);
void cas_pr(const char *format, int *i, va_list ap);
char *create_exec_path(char *path, char *arg);
int my_strcmp(char *str, char *scr);
void read_command(char **args, char **env, t_env *envi);
void cleanup(t_env *envi);
char *my_strdup(char *src);
int main(int argc, char **argv, char **env);
char *my_strcat(char *dest, char *src);
int my_strncmp(char *str1, char *str2, int n);
int my_getnbr(const char *str);
void cd_home(char **env);
void cd_old(char **env, t_env *envi);
void handle_cd(char **args, char **env, t_env *envi);
void handle_exit(char **args);
void handle_setenv(char **args, t_env *envi);
void free_word_array(char **words);
void check_sign(int status);
int is_alpha(char c);
void dex(char **args, char **env, char *exec_path);
void add_old(t_env *envi);
char *find_exec_path(char **args, char **env);
#endif
