##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile for the lib
##

SRC	=	framebuffer_create.c	\
		my_draw_square.c	 	\
		my_put_pixel.c			\
		my_draw_rect.c 			\

NAME	=	libgraphical.a

OBJ	=	$(SRC:.c=.o)

INC	=	-I./include

CFLAGS	=	$(INC) -Wall -Wextra -l c_graph_prog

CC	=	gcc

mklib:		all

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean: 	clean
		$(RM) $(NAME)

re:		fclean all
