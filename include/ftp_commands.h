/*
** EPITECH PROJECT, 2025
** add
** File description:
** add
*/

#ifndef FTP_COMMANDS_H
    #define FTP_COMMANDS_H

    #include "client.h"
    #include <stdio.h>
    #include <string.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <dirent.h>
    #include <errno.h>
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <sys/stat.h>
    #include <fcntl.h>
typedef int (*ftp_cmd_handler_t)(client_t *, const char *);

typedef struct {
    const char *name;
    ftp_cmd_handler_t handler;
    int need_auth;
} ftp_cmd_t;



int handle_ftp_command(client_t *client, const char *cmdline);
int handle_user_command(client_t *client, const char *arg);
int handle_pass_command(client_t *client, const char *arg);
int handle_quit_command(client_t *client, const char *arg);
int handle_feat_command(client_t *client, const char *arg);
int handle_syst_command(client_t *client, const char *arg);
int handle_help_command(client_t *client, const char *arg);
int handle_noop_command(client_t *client, const char *arg);
int handle_type_command(client_t *client, const char *arg);
int handle_port_command(client_t *client, const char *arg);
int handle_pasv_command(client_t *client, const char *arg);
int handle_pwd_command(client_t *client, const char *arg);
int handle_cwd_command(client_t *client, const char *arg);
int handle_cdup_command(client_t *client, const char *arg);
int handle_list_command(client_t *client, const char *arg);
int handle_dele_command(client_t *client, const char *arg);
int handle_mkd_command(client_t *client, const char *arg);
int handle_rmd_command(client_t *client, const char *arg);
int handle_stor_command(client_t *client, const char *arg);
int handle_retr_command(client_t *client, const char *arg);

static const ftp_cmd_t ftp_cmds[] = {
    {"USER", handle_user_command, 0},
    {"PASS", handle_pass_command, 0},
    {"QUIT", handle_quit_command, 0},
    {"PWD", handle_pwd_command, 1},
    {"CWD", handle_cwd_command, 1},
    {"CDUP", handle_cdup_command, 1},
    {"LIST", handle_list_command, 1},
    {"DELE", handle_dele_command, 1},
    {"MKD", handle_mkd_command, 1},
    {"RMD", handle_rmd_command, 1},
    {"TYPE", handle_type_command, 1},
    {"PORT", handle_port_command, 1},
    {"PASV", handle_pasv_command, 1},
    {"FEAT", handle_feat_command, 1},
    {"SYST", handle_syst_command, 1},
    {"HELP", handle_help_command, 1},
    {"NOOP", handle_noop_command, 1},
    {"STOR", handle_stor_command, 1},
    {"RETR", handle_retr_command, 1},
    {NULL, NULL, 0}
};

#endif
