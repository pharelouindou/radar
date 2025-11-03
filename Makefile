##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## compile
##

NAME    =     my_radar

SRCS    = $(wildcard *.c)

OBJS    = $(SRCS:.c=.o)

CFLAGS	= -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm
all: $(NAME)

$(NAME): $(OBJS)
	gcc -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
