##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## add
##

CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC = $(wildcard *src/*.c)
OBJ = $(SRC:.c=.o)
NAME = myftp

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
