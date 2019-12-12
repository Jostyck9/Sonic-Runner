#
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC	=	sources/recup_map/creation_ground.c 				\
		sources/animation_sonic.c 							\
		sources/check_window_size.c 						\
		sources/main.c										\
		sources/recup_map/count_size.c 						\
		sources/environment_detection/colision_detection.c 	\
		sources/initialisation/create_object.c 				\
		sources/initialisation/initialisation_all.c 		\
		sources/initialisation/initialisation_text.c 		\
		sources/initialisation/initialisation_sprite_menu.c \
		sources/check_ground_struct.c 						\
		sources/destroy/destroy_object.c 					\
		sources/destroy/destroy_all.c 						\
		sources/destroy/destroy_text.c 						\
		sources/destroy/destroy_sprites.c 					\
		sources/destroy/destroy_music.c 					\
		sources/manage_lvl/manage_lvl.c 					\
		sources/menu/menu_loop.c 							\
		sources/recup_map/open_file.c 						\
		sources/option_h.c 									\
		sources/recup_arg.c 								\
		sources/recup_map/recup_map.c 						\
		sources/recup_map/transform_map.c 					\
		sources/recup_map/transform_map2.c 					\
		sources/events.c 									\
		sources/game_loop.c 								\
		sources/initialisation/initialisation_sprites.c 	\
		sources/initialisation/re_initialisation.c 			\
		sources/initialisation/initialise_music.c 			\
		sources/environment_detection/fall_detection.c 		\
		sources/my_runner.c 								\
		sources/pause.c 									\
		sources/print_text/print_score.c					\
		sources/print_text/print_text.c 					\
		sources/print_text/my_put_nbr_str.c 				\
		sources/print_text/print_enter_alpha.c 				\
		sources/animation_end/animation_win.c 				\
		sources/animation_end/animation_loose.c 			\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

INC	=	-I./include -I./lib/my -I./lib/graphical/include/

LIBS	=	-L./lib/my -lmy 				\
			-L./lib/graphical/ -lgraphical

CFLAGS	=	$(INC) -Wextra -Wall -Werror

CC	=	gcc

LIB	= 	make -C lib/my/ && make -C lib/graphical

all:		$(NAME)

$(NAME):	$(OBJ)
		$(LIB)
		$(CC) -o $(NAME) $(OBJ) -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system $(LIBS) 

clean:
		$(RM) $(OBJ)
		make clean -C lib/my/
		make clean -C lib/graphical/

fclean: 	clean
		$(RM) $(NAME)
		make fclean -C lib/my/
		make fclean -C lib/graphical/

re:		fclean all

debug: 		CFLAGS += -g
debug:		re
