##
## EPITECH PROJECT, 2018
## 105torus
## File description:
## compilation
##

SRC =	main.c          \
        src/bisection.c \
        src/newton.c    \
        src/secant.c    \
        error/error.c

OBJ = $(SRC:.c=.o)

NAME = 105torus

LIBFLAG = gcc -o

CFLAG = -g3 -lm

all: $(NAME)

$(NAME): $(OBJ)
	$(LIBFLAG) $(NAME) $(OBJ) $(CFLAG) -g3

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re