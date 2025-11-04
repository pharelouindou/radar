/*
** EPITECH PROJECT, 2025
** add
** File description:
** Authentication commands
*/

#include "ftp_commands.h"

int handle_user_command(client_t *client, const char *arg)
{
    dprintf(client->fd, "331 Please specify the password.\r\n");
    client->authenticated = 0;
    strncpy(client->username, arg, sizeof(client->username) - 1);
    client->username[sizeof(client->username) - 1] = '\0';
    return 0;
}

int handle_pass_command(client_t *client, const char *arg)
{
    if (strcasecmp(client->username, "Anonymous") == 0) {
        client->authenticated = 1;
        dprintf(client->fd, "230 Login successful.\r\n");
    } else {
        dprintf(client->fd, "530 Login incorrect.\r\n");
    }
    return 0;
}

int handle_quit_command(client_t *client, const char *arg)
{
    (void)arg;
    dprintf(client->fd, "221 Goodbye.\r\n");
    return 1;
}
