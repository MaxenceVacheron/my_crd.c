##
## ETNA PROJECT, 29/03/2021 by vacher_m
## Static Library & libmy
## File description:
##      Makefile for my_crd project
##

CC      =   gcc

NAME    =   ./Release/my_crd

SRC_FILE=   my_crd.c                
            # my_putchar.c            \
            # my_putnbr.c             \
            # my_readline.c           \
            # my_str_to_int.c         \
            # my_str_to_array.c 


H_FILE  =   ./lib/my

SRCF 	=	$(addprefix libmy/, $(SRC_FILE))

OBJ     =   $(SRCF:%.c=%.o)

COMP    =   -Wall -Wextra -Werror -std=c11

RM      =   rm -f

$(NAME) :   $(OBJ)
		    $(CC) $(COMP) $(OBJ) -o $(NAME) -I $(H_FILE)

all     :   $(NAME)

clean   :   $(RM) $(OBJ)

fclean  :   clean

re      :   fclean all
