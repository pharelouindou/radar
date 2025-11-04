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
#include <sys/socket.h>
#include <netinet/in.h>
#include <poll.h>
#include <fcntl.h>
#include <errno.h>
#include "server.h"
#include "client.h"



int create_server_socket(int port)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    int opt = 1;
    struct sockaddr_in addr = {0};

    if (sock < 0)
        return -1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);
    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
        return -1;
    if (listen(sock, 5) < 0)
        return -1;
    return sock;
}

int handle_new_connection(int server_fd, struct pollfd *fds,
    client_t **clients, int *nfds, const char *home_path)
{
    int client_fd;

    if (fds[0].revents & POLLIN) {
        client_fd = accept(server_fd, NULL, NULL);
        if (client_fd >= 0 && *nfds < MAX_CLIENTS + 1) {
            fds[*nfds].fd = client_fd;
            fds[*nfds].events = POLLIN;
            clients[*nfds - 1] = create_client(client_fd, home_path);
            send_welcome(client_fd);
            (*nfds)++;
        }
    }
    return 0;
}

static void remove_client_at_index(struct pollfd *fds,
    client_t **clients, int *nfds, int index)
{
    close(fds[index].fd);
    free_client(clients[index - 1]);
    for (int j = index; j < *nfds - 1; ++j) {
        fds[j] = fds[j + 1];
        clients[j - 1] = clients[j];
    }
    clients[*nfds - 2] = NULL;
    (*nfds)--;
}

static int should_remove_client(struct pollfd *fds,
    client_t **clients, int index)
{
    if (!(fds[index].revents & POLLIN))
        return 0;
    return (handle_client(clients[index - 1]) != 0);
}

int handle_existing_clients(struct pollfd *fds, client_t **clients, int *nfds)
{
    for (int i = 1; i < *nfds; ++i) {
        if (should_remove_client(fds, clients, i)) {
            remove_client_at_index(fds, clients, nfds, i);
            i--;
        }
    }
    return 0;
}

static void setup_pollfd(struct pollfd *\
    fds, int server_fd)
{
    fds[0].fd = server_fd;
    fds[0].events = POLLIN;
}

static int initialize_server(int port)
{
    int server_fd = create_server_socket(port);

    if (server_fd < 0) {
        perror("socket");
        return -1;
    }
    return server_fd;
}

void server_loop(int server_fd, const char *home_path)
{
    int nfds = 1;
    int ret = 0;
    struct pollfd fds[MAX_CLIENTS + 1];
    client_t *clients[MAX_CLIENTS] = {0};

    setup_pollfd(fds, server_fd);
    while (1) {
        ret = poll(fds, nfds, -1);
        if (ret < 0) {
            perror("poll");
            break;
        }
        handle_new_connection(server_fd, fds, clients, &nfds, home_path);
        handle_existing_clients(fds, clients, &nfds);
    }
    close(server_fd);
}

int start_server(int port, const char *home_path)
{
    int server_fd = initialize_server(port);

    if (server_fd < 0)
        return 1;
    server_loop(server_fd, home_path);
    return 0;
}
