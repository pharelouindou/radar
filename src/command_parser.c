/*
** EPITECH PROJECT, 2025
** add
** File description:
** Command parsing and dispatching
*/

#include "ftp_commands.h"
#include <string.h>

static void parse_command_name(const char *cmdline, char *cmd, size_t cmd_size)
{
    size_t i = 0;

    memset(cmd, 0, cmd_size);
    while (*cmdline == ' ' || *cmdline == '\t') {
        cmdline++;
    }
    while (*cmdline && *cmdline != ' ' && *cmdline != '\t' &&
        *cmdline != '\r' && *cmdline != '\n' && i < cmd_size - 1) {
        cmd[i] = *cmdline;
        i++;
        cmdline++;
    }
    cmd[i] = '\0';
}

static void parse_command_arguments(const char *cmdline,
    char *arg, size_t arg_size)
{
    size_t i = 0;
    const char *start = cmdline;

    memset(arg, 0, arg_size);
    while (*start && *start != ' ' && *start != '\t' &&
        *start != '\r' && *start != '\n') {
        start++;
    }
    while (*start == ' ' || *start == '\t') {
        start++;
    }
    while (*start && *start != '\r' &&
        *start != '\n' && i < arg_size - 1) {
        arg[i] = *start;
        i++;
        start++;
    }
    while (i > 0 && (arg[i-1] == ' ' || arg[i-1] == '\t')) {
        i--;
    }
    arg[i] = '\0';
}

static void parse_command(const char *cmdline, char *cmd, size_t cmd_size, char *arg, size_t arg_size)
{
    parse_command_name(cmdline, cmd, cmd_size);
    parse_command_arguments(cmdline, arg, arg_size);
}

int handle_ftp_command(client_t *client, const char *cmdline)
{
    char cmd[16] = {0};
    char arg[512] = {0};

    parse_command(cmdline, cmd, sizeof(cmd), arg, sizeof(arg));
    for (int i = 0; ftp_cmds[i].name; ++i) {
        if (strcasecmp(cmd, ftp_cmds[i].name) == 0) {
            if (ftp_cmds[i].need_auth && !client->authenticated) {
                dprintf(client->fd, "530 Please login with USER and PASS.\r\n");
                return 0;
            }
            return ftp_cmds[i].handler(client, arg);
        }
    }
    dprintf(client->fd, "500 Command not implemented.\r\n");
    return 0;
}
