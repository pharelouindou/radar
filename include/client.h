/*
** EPITECH PROJECT, 2025
** add
** File description:
** add
*/

#ifndef CLIENT_H
    #define CLIENT_H
    #define MAX_CLIENTS 5000
    #include <stddef.h>
typedef struct client_s {
    int fd;
    int authenticated;
    char home[512];
    char cwd[512];
    int data_fd;
    int passive_fd;
    char username[64];
    size_t recv_len;
    int data_mode;
    int pasv_sock; // Ajouté pour le socket passif (PASV)
    // Pour le mode PORT (actif)
    char port_ip[16];
    int port_port;
} client_t;

client_t *create_client(int fd, const char *home);
void free_client(client_t *client);
int handle_client(client_t *client);
void send_welcome(int fd);

#endif
