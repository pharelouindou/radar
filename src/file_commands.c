/*
** EPITECH PROJECT, 2025
** add
** File description:
** File operation commands
*/

#include "ftp_commands.h"

int handle_dele_command(client_t *client, const char *arg)
{
    char path[1024];
    char real_del[1024];

    snprintf(path, sizeof(path), "%s/%s", client->cwd, arg);
    if (realpath(path, real_del) &&
    strncmp(real_del, client->home, strlen(client->home)) == 0) {
        if (unlink(real_del) == 0)
            dprintf(client->fd, "250 File deleted.\r\n");
        else
            dprintf(client->fd, "550 Delete operation failed.\r\n");
    } else {
        dprintf(client->fd, "550 Delete operation failed.\r\n");
    }
    return 0;
}

int handle_mkd_command(client_t *client, const char *arg)
{
    char path[1024];
    char real_mkd[1024];

    snprintf(path, sizeof(path), "%s/%s", client->cwd, arg);
    if (realpath(client->cwd, real_mkd) &&
    strncmp(real_mkd, client->home, strlen(client->home)) == 0) {
        if (mkdir(path, 0755) == 0)
            dprintf(client->fd, "257 Directory created.\r\n");
        else
            dprintf(client->fd, "550 Create directory operation failed.\r\n");
    } else {
        dprintf(client->fd, "550 Create directory operation failed.\r\n");
    }
    return 0;
}

int handle_rmd_command(client_t *client, const char *arg)
{
    char path[1024];
    char real_rmd[1024];

    snprintf(path, sizeof(path), "%s/%s", client->cwd, arg);
    if (realpath(path, real_rmd) &&
    strncmp(real_rmd, client->home, strlen(client->home)) == 0) {
        if (rmdir(real_rmd) == 0)
            dprintf(client->fd, "250 Directory removed.\r\n");
        else
            dprintf(client->fd, "550 Remove directory operation failed.\r\n");
    } else {
        dprintf(client->fd, "550 Remove directory operation failed.\r\n");
    }
    return 0;
}

int handle_stor_command(client_t *client, const char *arg)
{
    int data_fd = -1;
    char buf[1024];
    ssize_t r;
    char path[1024];
    int fd = -1;

    if (client->data_mode == 0) {
        dprintf(client->fd, "425 Use PORT or PASV first.\r\n");
        return 0;
    }
    if (arg == NULL || arg[0] == '\0') {
        dprintf(client->fd, "501 Syntax error in parameter or arguments.\r\n");
        return 0;
    }
    snprintf(path, sizeof(path), "%s/%s", client->cwd, arg);
    fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        dprintf(client->fd, "550 Failed to open file.\r\n");
        client->data_mode = 0;
        return 0;
    }
    dprintf(client->fd, "150 Ok to send data.\r\n");
    if (client->data_mode == 1 && client->pasv_sock != -1) {
        data_fd = accept(client->pasv_sock, NULL, NULL);
        if (data_fd != -1) {
            while ((r = read(data_fd, buf, sizeof(buf))) > 0) {
                write(fd, buf, r);
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
            while ((r = read(data_fd, buf, sizeof(buf))) > 0) {
                write(fd, buf, r);
            }
            close(data_fd);
        } else if (data_fd != -1) {
            close(data_fd);
        }
    }
    close(fd);
    dprintf(client->fd, "226 Transfer complete.\r\n");
    client->data_mode = 0;
    return 0;
}

int handle_retr_command(client_t *client, const char *arg)
{
    char path[1024];
    char real_path[1024];
    int fd = -1;
    int data_fd = -1;
    ssize_t r;
    char buf[1024];

    if (client->data_mode == 0) {
        dprintf(client->fd, "425 Use PORT or PASV first.\r\n");
        return 0;
    }
    if (arg == NULL || arg[0] == '\0') {
        dprintf(client->fd, "501 Syntax error in parameter or arguments.\r\n");
        return 0;
    }
    snprintf(path, sizeof(path), "%s/%s", client->cwd, arg);
    if (!realpath(path, real_path) ||
        strncmp(real_path, client->home, strlen(client->home)) != 0) {
        dprintf(client->fd, "550 Failed to open file.\r\n");
        client->data_mode = 0;
        return 0;
    }
    fd = open(real_path, O_RDONLY);
    if (fd < 0) {
        dprintf(client->fd, "550 Failed to open file.\r\n");
        client->data_mode = 0;
        return 0;
    }
    dprintf(client->fd, "150 Opening data connection.\r\n");
    if (client->data_mode == 1 && client->pasv_sock != -1) {
        data_fd = accept(client->pasv_sock, NULL, NULL);
        if (data_fd != -1) {
            while ((r = read(fd, buf, sizeof(buf))) > 0) {
                write(data_fd, buf, r);
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
            while ((r = read(fd, buf, sizeof(buf))) > 0) {
                write(data_fd, buf, r);
            }
            close(data_fd);
        } else if (data_fd != -1) {
            close(data_fd);
        }
    }
    close(fd);
    dprintf(client->fd, "226 Transfer complete.\r\n");
    client->data_mode = 0;
    return 0;
}
