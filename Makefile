# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/27 21:46:39 by dselmy            #+#    #+#              #
#    Updated: 2022/05/14 21:48:01 by hashly           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BIN_DIR =			./bin/

NAME =				$(BIN_DIR)cub3D

LIBFT_PATH			=	./libft/
LIBFT_NAME			=	libft.a
LIBFT				=	$(addprefix $(LIBFT_PATH), $(LIBFT_NAME))

MLX_PATH			=	./mlx_linux/
MLX_NAME			=	libmlx.a
MLX					=	$(addprefix $(MLX_PATH), $(MLX_NAME))

SRC_DIR = 			./src/
INC_DIR =			./inc/
OBJ_DIR =			./obj/

INC_NAME = 			cub3d.h
SRCS_NAME =			cub3d.c \
					free.c \
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
					parser_player.c \
					player_rotate.c \
					put_ray.c \
					put_screen.c \
					shutdown.c \
					utils.c \
					utils_get_wall.c \
					utils_mlx.c \
					get_distance.c \
					get_crossing.c

INC				= $(addprefix $(INC_DIR), $(INC_NAME))
SRCS			= $(addprefix $(SRC_DIR), $(SRCS_NAME))
OBJ				= $(addprefix $(OBJ_DIR), $(SRCS_NAME:.c=.o))
DEP				= $(addprefix $(OBJ_DIR), $(SRCS_NAME:.c=.d))

MLX_FLAGS =		-lXext -lX11 -lm -lbsd
CFLAGS =		-Wall -Werror -Wextra -O3

all: libs $(BIN_DIR) $(OBJ_DIR) $(NAME)

$(BIN_DIR):
	mkdir $(BIN_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	gcc -o $(NAME) $(CFLAGS) -I $(INC_DIR) $(OBJ) -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx $(MLX_FLAGS)
	cp $(NAME) ./

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	gcc -c $(CFLAGS) -I $(INC_DIR) $< -o $@ -MD

libs:
	@make -C $(LIBFT_PATH)
	@make -C $(MLX_PATH)

clean:	clean_libs
	rm -rf $(OBJ_DIR) $(DEP)

clean_libs:
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(MLX_PATH)

fclean: clean
	rm -rf $(BIN_DIR) ./cub3D $(LIBFT) $(MLX)

re: fclean all

include $(wildcard $(DEP))

.PHONY: all clean fclean re
