# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/27 21:46:39 by dselmy            #+#    #+#              #
#    Updated: 2022/05/11 15:55:39 by hashly           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BIN_DIR =			./bin/

NAME =				$(BIN_DIR)cub3d

INC_DIR =			./includes/
MLX_DIR =			./mlx_linux/
LIBFT_DIR =			./libft/

SRCS =			./cub3d.c \
				./draw.c \
				./get_texture.c \
				./init.c \
				./parse_end.c \
				./parser_map.c \
				./raycast_draft.c \
				./start_game.c \
				./game_utils.c \
				./parse_config.c \
				./parser_base.c \
				./parser_map_utils.c \
				./player_movement.c \
				./player_rotate.c \
				./shutdown.c \
				./utils.c \
				./utils_get_wall.c \
				./get_distance.c \
				./get_crossing.c

MLX_FLAGS =		-lXext -lX11 -lm -lbsd
CFLAGS =		-Wall -Werror -Wextra -O3

OBJ = $(SRCS:.c=.o)
DEP = $(SRCS:.c=.d)

all: $(BIN_DIR) $(NAME)

$(BIN_DIR):
		mkdir $(BIN_DIR)

$(NAME): $(OBJ)
		@make -C $(LIBFT_DIR)
		@make -C $(MLX_DIR)
		gcc -o $(NAME) $(CFLAGS) -I$(INC_DIR) $(OBJ) $(LIBFT_DIR)libft.a \
		$(MLX_DIR)libmlx.a $(MLX_FLAGS)
		cp $(NAME) ./

%.o:	%.c
		gcc -c $(CFLAGS) -I$(INC_DIR) $< -o $@ -MD

clean:
		@make clean -C $(LIBFT_DIR)
		@make clean -C $(MLX_DIR)
		rm -f $(OBJ) $(DEP)

fclean: clean
		@make fclean -C $(LIBFT_DIR)
		rm -rf $(BIN_DIR) ./cub3d

re: fclean all


include $(wildcard $(DEP))

.PHONY: all clean fclean re

