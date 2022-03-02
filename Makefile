# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdal-mol <dolmalinn@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 12:51:57 by pdal-mol          #+#    #+#              #
#    Updated: 2022/03/01 13:16:30by pdal-mol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =				so_long

PARSING =			\
					check_input.c\
					exit.c

MAP_HANDLING =		\
					init_data.c\
					check_map.c\
					is_in_charset.c\
					clear_data.c

GRAPHIC_HANDLING =	\
					init_window.c\
					init_img.c\
					put_img.c\
					get_img.c\
					run_game.c

ACTION =			\
					update_user_pos.c\
					exec_action.c\
					exec_move.c\
					move.c

FILES =				\
					$(addprefix parsing/,$(PARSING))\
					$(addprefix map_handling/,$(MAP_HANDLING))\
					$(addprefix graphic_handling/,$(GRAPHIC_HANDLING))\
					$(addprefix action/,$(ACTION))\
					main.c

LIB =				./libft/libft.a ./mlx/libmlx.a

SRCS =				$(addprefix ./srcs/,$(FILES))

OBJ =				$(SRCS:.c=.o)

FLAGS =				-Wall -Wextra -Werror

FLAGSX =			-L mlx -l mlx -framework OpenGL -framework Appkit

all:				library $(NAME)

%.o:%.c				./includes/so_long.h $(LIB)
					gcc $(FLAGS) -Imlx -c $< -o $@

$(NAME):			$(OBJ) $(LIB)
					gcc $(FLAGS) $(OBJ) $(LIB) -o $(NAME) $(FLAGSX)

library: 
					make -C ./libft
					make -C ./mlx

clean:
					make -C ./libft clean
					make -C ./mlx clean
					/bin/rm -rf $(OBJ)

fclean:				clean
					/bin/rm -rf libft/libft.a
					/bin/rm -rf mlx/libmlx.a
					/bin/rm -rf $(NAME)

re:					fclean all

.PHONY:			all clean fclean library re
