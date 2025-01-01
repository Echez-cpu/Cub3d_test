# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/27 03:26:25 by pokpalae          #+#    #+#              #
#    Updated: 2025/01/01 16:41:57 by pokpalae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3D

CC		= cc
CFLAGS	= -Werror -Wextra -Wall -g3 #-fsanitize=address

MLX_PATH	= minilibx-linux/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

LIBFT_PATH	= libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

SRC		= \
	main.c \
	cam_move.c \
	camera_movement.c \
	cast_rays.c \
	game_state.c \
	free_me.c \
	parsing/mapfile_check.c \
	parsing/set_info_1.c \
	parsing/set_info_2.c \
	parsing/set_info_3.c \
	parsing/set_map.c \
	parsing/camera_angles.c \
	parsing/utils.c \
	parsing/cam_position.c \
	parsing/validity_check_1.c \
	parsing/validity_check_block.c\
	parsing/texture_encoded.c\
	handle_render.c \
	keyboard_handler.c \
	mlx_folder.c \
	setup_textures.c \
	ray_traversal.c \
	cam_move_2.c
SRCS	= $(addprefix ,$(SRC))

OBJ_PATH	= ./objects/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

INC			= \
	-I ./includes/ \
	-I ./libft/ \
	-I ./minilibx-linux/

all: $(OBJ_PATH) $(MLX) $(LIBFT) $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)
	mkdir -p $(OBJ_PATH)parsing

$(OBJ_PATH)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LIBFT) $(MLX) -lXext -lX11 -lm

$(LIBFT):
	make -sC $(LIBFT_PATH)


$(MLX):
	make -sC $(MLX_PATH)

bonus:
	make all BONUS=1

clean:
	rm -rf $(OBJ_PATH)
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all re clean fclean bonus
