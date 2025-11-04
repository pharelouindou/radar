/*
** EPITECH PROJECT, 2025
** add
** File description:
** add
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "client.h"
#include "ftp_commands.h"

client_t *create_client(int fd, const char *home)
{
    client_t *c = calloc(1, sizeof(client_t));

    if (!c)
        return NULL;
    c->fd = fd;
    c->authenticated = 0;
    strncpy(c->home, home, sizeof(c->home) - 1);
    strncpy(c->cwd, home, sizeof(c->cwd) - 1);
    c->data_fd = -1;
    c->passive_fd = -1;
    c->username[0] = '\0';
    c->data_mode = 0;
    return c;
}

void free_client(client_t *client)
{
    if (!client)
        return;
    if (client->data_fd != -1)
        close(client->data_fd);
    if (client->passive_fd != -1)
        close(client->passive_fd);
    free(client);
}

void send_welcome(int fd)
{
    dprintf(fd, "220 Welcome to myftp server\r\n");
}

int handle_client(client_t *client)
{
    char buf[1024] = {0};
    ssize_t r = read(client->fd, buf, sizeof(buf) - 1);

    if (r <= 0)
        return 1;
    buf[r] = 0;
    return handle_ftp_command(client, buf);
}
