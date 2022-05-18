# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/27 21:46:39 by dselmy            #+#    #+#              #
#    Updated: 2022/05/18 15:35:44 by hashly           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BIN_DIR				=	./bin/

NAME				=	$(BIN_DIR)cub3D
NAME_BONUS			=	$(BIN_DIR)cub3D_bonus

LIBFT_PATH			=	./libft/
LIBFT_NAME			=	libft.a
LIBFT				=	$(addprefix $(LIBFT_PATH), $(LIBFT_NAME))

MLX_PATH			=	./mlx_linux/
MLX_NAME			=	libmlx.a
MLX					=	$(addprefix $(MLX_PATH), $(MLX_NAME))

SRC_DIR				=	./src/
SRC_BONUS_DIR		=	./src_bonus/
INC_DIR				=	./inc/
OBJ_DIR				=	./obj/

INC_NAME			=	cub3d.h

SRCS_COMMON			=	cub3d.c \
						error.c \
						free.c \
						init_mlx.c \
						init.c \
						key_handle.c \
						parse_end.c \
						parser_map.c \
						parse_config.c \
						parser_base.c \
						parser_map_utils.c \
						player_movement.c \
						parser_player.c \
						player_rotate.c \
						put_ray.c \
						shutdown.c \
						utils.c \
						utils_get_wall.c \
						utils_mlx.c \
						utils_parser.c \
						utils_put_wall.c \
						get_distance.c \
						get_crossing.c

SRCS_ONLY_MANDATORY	=	put_screen.c \
						start_game.c

SRCS_ONLY_BONUS		=	put_screen_bonus.c \
						start_game_bonus.c

SRCS_FILE			=	$(SRCS_COMMON) $(SRCS_ONLY_MANDATORY)
SRCS_FILE_BONUS		=	$(SRCS_COMMON) $(SRCS_ONLY_BONUS)

SRCS_NAME				=	$(addprefix $(SRC_DIR), $(SRCS_COMMON)) $(addprefix $(SRC_DIR), $(SRCS_ONLY_MANDATORY))
SRCS_NAME_BONUS			=	$(addprefix $(SRC_DIR), $(SRCS_COMMON)) $(addprefix $(SRC_DIR), $(SRCS_ONLY_BONUS))


INC					=	$(addprefix $(INC_DIR), $(INC_NAME))
OBJ					=	$(addprefix $(OBJ_DIR), $(SRCS_FILE:.c=.o))
OBJ_BONUS			=	$(addprefix $(OBJ_DIR), $(SRCS_FILE_BONUS:.c=.o))
DEP					=	$(addprefix $(OBJ_DIR), $(SRCS_NAME:.c=.d))

MLX_FLAGS			=	-lXext -lX11 -lm -lbsd
CFLAGS				=	-Wall -Werror -Wextra -O3

all: libs $(BIN_DIR) $(OBJ_DIR) $(NAME)

bonus: libs $(BIN_DIR) $(OBJ_DIR) $(NAME_BONUS)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	gcc -o $(NAME) $(CFLAGS) -I $(INC_DIR) $(OBJ) -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx $(MLX_FLAGS)
# cp $(NAME_BONUS) ./

$(NAME_BONUS): $(LIBFT) $(MLX) $(OBJ_BONUS)
	gcc -o $(NAME_BONUS) $(CFLAGS) -I $(INC_DIR) $(OBJ_BONUS) -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx $(MLX_FLAGS)
# cp $(NAME) ./

$(BIN_DIR):
	mkdir $(BIN_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	gcc -c $(CFLAGS) -I $(INC_DIR) $< -o $@ -MD

$(OBJ_DIR)%.o: $(SRC_BONUS_DIR)%.c
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

.PHONY: all clean fclean re bonus
