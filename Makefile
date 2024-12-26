
NAME	= cub3D

CC		= gcc
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
	parsing/tester.c \
	parsing/utils.c \
	parsing/cub3d.c \
	parsing/validity_check_1.c \
	parsing/validity_check_block.c\
	handle_render.c \
	keyboard_handler.c \
	mlx_folder.c \
	test.c
SRCS	= $(addprefix ,$(SRC))

# Objects
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
	$(CC) $(CFLAGS) -DBONUS=$(BONUS) -c $< -o $@ $(INC)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -DBONUS=$(BONUS) $(OBJS) -o $@ $(LIBFT) $(MLX) -lXext -lX11 -lm

$(LIBFT):
	make -sC $(LIBFT_PATH)


$(MLX):
	make -sC $(MLX_PATH)

bonus:
	make all BONUS=1

# Clean up build files rule
clean:
	rm -rf $(OBJ_PATH)
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean

# Remove program executable
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

# Clean + remove executable
re: fclean all

.PHONY: all re clean fclean bonus
