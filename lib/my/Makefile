##
## EPITECH PROJECT, 2019
## C Pool EvalExpr
## File description:
## libmy Makefile
##

CC = gcc

SRC = 	./my_put_nbr.c \
	./my_putchar.c \
	./my_putstr.c \
	./my_strcmp.c \
	./my_strlen.c \
	./create_sprite.c \
	./create_rect.c \
	./create_vect.c \
	./calcul_vect.c \
	./check_if_passed.c \
	./square_root.c \
	./my_get_denominator.c \
	./my_intlen.c \
	./my_int_to_strnum.c \
	./change_rect.c \

OBJ = $(SRC:.c=.o)

NAME = libmy.a

HEADERS = my.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
	cp $(HEADERS) ../../include/

clean:
	  rm -f $(OBJ)

fclean: clean
	  rm -f $(NAME)
	  rm -f ../$(NAME)
	  rm -f ../../include/my.h

re: fclean all
