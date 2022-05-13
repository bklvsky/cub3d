# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/27 21:46:39 by dselmy            #+#    #+#              #
#    Updated: 2022/05/13 15:44:01 by dselmy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BIN_DIR =			./bin/

NAME =				$(BIN_DIR)cub3d

MLX_DIR =			./mlx_linux/
LIBFT_DIR =			./libft/
OBJ_DIR =			./obj/

SRCS =			cub3d.c \
				init_mlx.c \
				init.c \
				key_handle.c \
				parse_end.c \
				parser_map.c \
				start_game.c \
				parse_config.c \
				parser_base.c \
				parser_map_utils.c \
				player_movement.c \
				player_rotate.c \
				put_ray.c \
				put_screen.c \
				shutdown.c \
				utils.c \
				utils_get_wall.c \
				utils_mlx.c \
				get_distance.c \
				get_crossing.c

MLX_FLAGS =		-lXext -lX11 -lm -lbsd
CFLAGS =		-Wall -Werror -Wextra -O3

OBJ = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
DEP = $(addprefix $(OBJ_DIR), $(SRCS:.c=.d))

all: $(BIN_DIR) $(OBJ_DIR) $(NAME)

$(BIN_DIR):
		mkdir $(BIN_DIR)

$(OBJ_DIR):
		mkdir $(OBJ_DIR)

$(NAME): $(OBJ)
		@make -C $(LIBFT_DIR)
		@make -C $(MLX_DIR)
		gcc -o $(NAME) $(CFLAGS) -I../ $(OBJ) $(LIBFT_DIR)libft.a \
		../$(MLX_DIR)libmlx.a $(MLX_FLAGS)
		cp $(NAME) ./

$(OBJ_DIR)%.o: %.c
		gcc -c $(CFLAGS) -I../ $< -o $@ -MD

clean:
		@make clean -C $(LIBFT_DIR)
		@make clean -C $(MLX_DIR)
		rm -rf $(OBJ_DIR) $(DEP)

fclean: clean
		@make fclean -C $(LIBFT_DIR)
		rm -rf $(BIN_DIR) ./cub3d

re: fclean all


include $(wildcard $(DEP))

.PHONY: all clean fclean re
