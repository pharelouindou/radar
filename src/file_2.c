/*
** EPITECH PROJECT, 2025
** add
** File description:
** add
*/

#include "ftp_commands.h"
#include <unistd.h>

int handle_port_command(client_t *client, const char *arg)
{
    int h1, h2, h3, h4, p1, p2;

    if (!arg) {
        dprintf(client->fd, "501 Syntax error in parameters or arguments.\r\n");
        return 0;
    }
    if (sscanf(arg, "%d,%d,%d,%d,%d,%d", &h1, &h2, &h3, &h4, &p1, &p2) != 6) {
        dprintf(client->fd, "501 Syntax error in parameters or arguments.\r\n");
        return 0;
    }
    snprintf(client->port_ip, sizeof(client->port_ip), "%d.%d.%d.%d", h1, h2, h3, h4);
    client->port_port = p1 * 256 + p2;
    client->data_mode = 2;
    dprintf(client->fd, "200 PORT command successful.\r\n");
    return 0;
}

int handle_pasv_command(client_t *client, const char *arg)
{
    (void)arg;
    int pasv_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (pasv_sock < 0) {
        dprintf(client->fd, "425 Can't open passive connection.\r\n");
        return -1;
    }
    struct sockaddr_in pasv_addr = {0};
    pasv_addr.sin_family = AF_INET;
    pasv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    pasv_addr.sin_port = 0;
    if (bind(pasv_sock, (struct sockaddr *)&pasv_addr, sizeof(pasv_addr)) < 0 ||
        listen(pasv_sock, 1) < 0) {
        close(pasv_sock);
        dprintf(client->fd, "425 Can't open passive connection.\r\n");
        return -1;
    }
    socklen_t addrlen = sizeof(pasv_addr);
    if (getsockname(pasv_sock, (struct sockaddr *)&pasv_addr, &addrlen) < 0) {
        close(pasv_sock);
        dprintf(client->fd, "425 Can't get passive port.\r\n");
        return -1;
    }
    unsigned short port = ntohs(pasv_addr.sin_port);
    dprintf(client->fd, "227 Entering Passive Mode (127,0,0,1,%u,%u).\r\n",
            port >> 8, port & 0xFF);

    client->data_mode = 1;
    client->pasv_sock = pasv_sock;
    return 0;
}
