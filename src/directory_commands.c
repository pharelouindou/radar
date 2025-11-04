/*
** EPITECH PROJECT, 2025
** add
** File description:
** Directory navigation commands
*/

#include "ftp_commands.h"

int handle_pwd_command(client_t *client, const char *arg)
{
    (void)arg;
    dprintf(client->fd, "257 \"%s\"\r\n", client->cwd);
    return 0;
}

int handle_cwd_command(client_t *client, const char *arg)
{
    char new_path[1024];
    char real_new[1024];

    if (arg == NULL || arg[0] == '\0') {
        dprintf(client->fd, "501 Syntax error in parametersor arguments.\r\n");
        return 0;
    }
    if (arg[0] == '/') {
        snprintf(new_path, sizeof(new_path), "%s%s", client->home, arg);
    } else {
        snprintf(new_path, sizeof(new_path), "%s/%s", client->cwd, arg);
    }
    if (realpath(new_path, real_new) &&
    strncmp(real_new, client->home, strlen(client->home)) == 0) {
        strncpy(client->cwd, real_new, sizeof(client->cwd) - 1);
        client->cwd[sizeof(client->cwd) - 1] = '\0';
        dprintf(client->fd, "250 Directory successfully changed.\r\n");
    } else {
        dprintf(client->fd, "550 Failed to change directory.\r\n");
    }
    return 0;
}

int handle_cdup_command(client_t *client, const char *arg)
{
    (void)arg;
    return handle_cwd_command(client, "..");
}

static void send_directory_listing(client_t *client, DIR *dir)
{
    struct dirent *entry;

    dprintf(client->fd, "150 Here comes the directory listing.\r\n");
    entry = readdir(dir);
    while (entry != NULL) {
        if (strcmp(entry->d_name, ".") != 0 &&
        strcmp(entry->d_name, "..") != 0) {
            dprintf(client->fd, "%s\r\n", entry->d_name);
        }
        entry = readdir(dir);
    }
    dprintf(client->fd, "226 Directory send OK.\r\n");
}

int handle_list_command(client_t *client, const char *arg)
{
    DIR *dir;
    int data_fd = -1;

    (void)arg;
    printf("Data mode: %d\n", client->data_mode);
    if (client->data_mode == 0) {
        dprintf(client->fd, "425 Use PORT or PASV first.\r\n");
        return 0;
    }
    dir = opendir(client->cwd);
    if (!dir) {
        dprintf(client->fd, "550 Failed to open directory.\r\n");
    } else {
        dprintf(client->fd, "150 Here comes the directory listing.\r\n");
        if (client->data_mode == 1 && client->pasv_sock != -1) {
            data_fd = accept(client->pasv_sock, NULL, NULL);
            if (data_fd != -1) {
                struct dirent *entry;
                while ((entry = readdir(dir)) != NULL) {
                    if (strcmp(entry->d_name, ".") && strcmp(entry->d_name, ".."))
                        dprintf(data_fd, "%s\r\n", entry->d_name);
                }
                close(data_fd);
            }
            close(client->pasv_sock);
            client->pasv_sock = -1;
        } else if (client->data_mode == 2) {
            struct sockaddr_in cli_addr = {0};
            cli_addr.sin_family = AF_INET;
            cli_addr.sin_port = htons(client->port_port);
            inet_pton(AF_INET, client->port_ip, &cli_addr.sin_addr);
            data_fd = socket(AF_INET, SOCK_STREAM, 0);
            if (data_fd != -1 && connect(data_fd, (struct sockaddr *)&cli_addr, sizeof(cli_addr)) == 0) {
                struct dirent *entry;
                while ((entry = readdir(dir)) != NULL) {
                    if (strcmp(entry->d_name, ".") && strcmp(entry->d_name, ".."))
                        dprintf(data_fd, "%s\r\n", entry->d_name);
                }
                close(data_fd);
            } else if (data_fd != -1) {
                close(data_fd);
            }
        }
        closedir(dir);
        dprintf(client->fd, "226 Directory send OK.\r\n");
    }
    client->data_mode = 0;
    return 0;
}
