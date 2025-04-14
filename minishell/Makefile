##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Calls the Makefile in lib/my
##

SRC 		=		src/main.c			\
					src/external.c		\
					src/builtin.c		\
					src/builtin2.c		\
					src/builtin3.c		\
					src/utils.c			\

OBJ			=		$(SRC:.c=.o)

NAME		=		mysh

CFLAGS		=		-L./lib/my -lmy

VFLAG		=		-g3

all:	$(OBJ)
		make -C lib/my/
		gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		rm -f $(OBJ)
		rm -f lib/my/*.o

fclean:	clean
		rm -f $(NAME)
		rm -f lib/my/*.a

re:		fclean all
