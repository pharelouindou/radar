/*
** EPITECH PROJECT, 2025
** add
** File description:
** Control and information commands
*/

#include "ftp_commands.h"

int handle_feat_command(client_t *client, const char *arg)
{
    (void)arg;
    dprintf(client->fd, "211-Features:\r\n");
    dprintf(client->fd, " PWD\r\n LIST\r\n CWD\r\n");
    dprintf(client->fd, "HELP\r\n NOOP\r\n DELE\r\n MKD\r\n RMD\r\n TYPE\r\n");
    dprintf(client->fd, "211 End\r\n");
    return 0;
}

int handle_syst_command(client_t *client, const char *arg)
{
    (void)arg;
    dprintf(client->fd, "215 UNIX Type: L8\r\n");
    return 0;
}

int handle_help_command(client_t *client, const char *arg)
{
    (void)arg;
    dprintf(client->fd, "214-The following commands are recognized:\r\n");
    dprintf(client->fd, " USER PASS QUIT PWD CWD LIST HELP NOOP\r\n");
    dprintf(client->fd, "214 Help OK.\r\n");
    return 0;
}

int handle_noop_command(client_t *client, const char *arg)
{
    (void)arg;
    dprintf(client->fd, "200 NOOP ok.\r\n");
    return 0;
}

int handle_type_command(client_t *client, const char *arg)
{
    if (strcasecmp(arg, "I") == 0) {
        dprintf(client->fd, "200 Switching to Binary mode.\r\n");
    } else if (strcasecmp(arg, "A") == 0) {
        dprintf(client->fd, "200 Switching to ASCII mode.\r\n");
    } else
        dprintf(client->fd, "504 Command nofor that parameter.\r\n");
    return 0;
}
