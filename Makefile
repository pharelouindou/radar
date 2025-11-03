##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## add
##

LIBNAME	=	mysh

SRC	=	arrays.c	\
		builtin.c	\
		code.c	\
		cons.c	\
		dex.c	\
		exec.c	\
		fil.c	\
		function.c	\
		list.c	\
		minishell.c	\
		my.c	\
		our.c	\
		tools.c	\
		type.c	\
		my_printf.c	\
		vin.c	\
		execute.c

OBJ	=	$(SRC:.c=.o)

autre 	= 	*~	\
		*.log	\
		a.out	\
		*.gcov	\
		*.gcno	\
		*.gcda

all	: 	$(LIBNAME)

$(LIBNAME):	$(OBJ)
		gcc $(SRC) main.c -o $(LIBNAME) -g3

clean:
		rm -f $(OBJ)
fclean:		clean
		rm -f $(LIBNAME) $(autre) 	unit_tests

re:		fclean all

unit_tests :	fclean $(LIBNAME)
	     	gcc $(SRC) tests/*.c -o unit_tests \
			-coverage -lcriterion -lgcov

tests_run :	unit_tests
		./unit_tests
		gcovr
		gcovr --exclude tests/test
		gcovr --exclude tests/test/ --branches
