/*
** EPITECH PROJECT, 2025
** add
** File description:
** add
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "server.h"

int main(int argc, char **argv)
{
    int port = atoi(argv[1]);
    struct stat st;

    if (argc != 3) {
        printf("USAGE: ./myftp port path\n");
        return 84;
    }
    if (port <= 0) {
        fprintf(stderr, "Invalid port\n");
        return 84;
    }
    if (stat(argv[2], &st) != 0 || !S_ISDIR(st.st_mode)) {
        fprintf(stderr, "Invalid home directory\n");
        return 84;
    }
    if (start_server(port, argv[2]) != 0) {
        fprintf(stderr, "Failed to start server\n");
        return 84;
    }
    return 0;
}
