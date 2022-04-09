gcc -Wall -Werror -Wextra \
cub3d.c \
utils.c \
init.c \
parser_base.c \
parse_config.c \
parser_map.c \
parse_end.c \
parser_map_utils.c \
shutdown.c \
start_game.c \
game_utils.c \
raycast_draft.c \
./libft/libft.a -L./libft ./mlx_linux/libmlx.a -lXext -lX11 -lm -lbsd
