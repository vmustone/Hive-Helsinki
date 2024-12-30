# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aotsala <aotsala@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 07:43:12 by vmustone          #+#    #+#              #
#    Updated: 2024/01/12 15:51:39 by aotsala          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = cub3D

Libft = libft/libft.a
MLX = MLX42/build/libmlx42.a
GLFW = $(shell brew --prefix glfw)
FRAMEWORK =	-framework Cocoa -framework OpenGL -framework IOKit

Flags = -Wall -Werror -Wextra

Src = main.c map_valid/map_init.c map_valid/header_and_map.c \
		map_valid/validate.c map_valid/validate_utils.c \
		map_valid/map_parse.c map_valid/rgb_to_str.c \
		\
		ray_cast/init.c ray_cast/help.c ray_cast/move.c \
		ray_cast/move_help.c ray_cast/draw.c ray_cast/draw_picture.c

Obj = $(Src:%.c=%.o)

all: $(Name) $(Libft)

$(MLX):
	cd MLX42 && cmake -B build && cmake --build build -j4

$(Libft):
	make -C libft

$(Name): $(MLX) $(Obj) $(Libft)
	cc $(Flags) $(MLX) $(FRAMEWOK) -L $(GLFW)/lib -lglfw $(Obj) $(Libft) -o $(Name)

%.o : %.c
	cc $(Flags) -c $< -o $@

clean:
	rm -f $(Obj)
	rm -rf MLX42/build
	make clean -C libft

fclean: clean
	rm -f $(Name) $(Libft)

re: fclean all

.phony: all clean fclean re