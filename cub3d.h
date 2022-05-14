/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 20:50:39 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/14 19:39:21 by hashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <string.h> //strerror
# include <errno.h> //errno apparently
# include <fcntl.h> //open, close
# include <stdlib.h>
# include <stdio.h> //perror
# include "./libft/libft.h"
# include "./mlx_linux/mlx.h"

# define SCALE 256
# define START_STEP 2
# define FINISH_STEP 0.05
# define PLR_SPEED 20
# define FOV_DEG 60

# define NO_TEX 0
# define SO_TEX 1
# define WE_TEX 2
# define EA_TEX 3
# define FLOOR_COL 4
# define CEIL_COL 5
# define MAP 6

# define SIZE_DATA 7

# define ERR_STD -14
# define ERR_ARG_NO_FILE -1
# define ERR_TOO_MANY_ARG -2
# define ERR_ARG_FORMAT -3
# define ERR_ARG_UNKNOWN -4
# define ERR_MISSING_CONF_DATA -5
# define ERR_RESOLUTION -6
# define ERR_TEX_FORMAT -7
# define ERR_COLOR -8
# define ERR_NO_MAP -9
# define ERR_SYM_AFTER_MAP -10
# define ERR_UKNOWN_SYM -11
# define ERR_NOT_CLOSED_MAP -12
# define ERR_DUPL_DATA -13
# define ERR_NO_PLR -15
# define ERR_MULT_PLRS -16

# define GET_PLR_Y -2

# define KEY_A 97
# define KEY_W 119
# define KEY_D 100
# define KEY_S 115
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307

typedef struct s_img
{
	void		*img;
	void		*addr;
	int			line_len;
	int			bpp;
	int			en;
	int			height;
	int			width;
	int			x;
}				t_img;

typedef struct	s_win
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*buf;
	void		*addr;
	int			line_len;
	int			bpp;
	int			en;
	int			x_win;
	int			y_win;
	t_img		textures[4];
	int			floor_color;
	int			ceil_color;
	double		prop;
}				t_win;

typedef struct	s_config
{
	char		*tex_paths[4];
	int			*ceil_color;
	int			*floor_color;
}				t_config;

typedef struct	s_crs
{
	double		angle;
	double		sin_angle;
	double		cos_angle;
	double		x;
	double		y;
	double		dist;
	int			side;
}				t_crs;

typedef struct	s_plr
{
	int			plr_num;
	double		plr_pos_x;
	double		plr_pos_y;
	double		plr_dir_rad;
	double		*correction;
	int			x_win;
	int			y_win;
	t_crs		cross;
}				t_plr;

typedef struct	s_data
{
	int			fd;
	char		**map;
	int			map_h;
	int			map_width;
	t_config	*cnfg;
	t_plr		*plr_data;
	t_win		*win;
}				t_data;

int		init_struct(t_data *all);
int		init_config(t_config **cnfg);
int		init_plr(t_plr	**plr_data);
void	init_cross(t_plr *plr, double angle);

void	check_arg(int argc, char **argv, t_data *all);
int		check_file_format(char *file_name, char *format);
int		only_num(const char *line);
void	free_arr(char **arr);
int		create_trgb(int t, int r, int g, int b);

void	shut_down(t_data *all, int error);
void	free_all(t_data *all);
void	manage_config_errors(int error);
void	manage_arg_errors(int error);
// void	free_config(t_data *all);

int		make_map_arr(t_data *all, t_list **map_ptr, int map_h);
int		read_config(int fd, t_list **head);
int		parse_config(t_data *all, t_list *cnfg_lst);
int		parse_map(t_data *all, t_list **map_ptr);
void	get_plr_dir(char c, t_plr *plr_data);
void	parser(t_data *all);

/*parse config*/
int		check_id(int id_number, t_config *cnfg, char *line);
int		parse_color(int	*color, char *line);
int		parse_tex_pth(char **tex_path, char *line);
void	check_all_data(t_data *all);
char	*get_identifier(int id_number);

int		parse_color_end(char **array, char *line_wo_spaces, int error);

/*map parsing utils*/

int		get_map_h(t_list *lst);
void	get_x_max(int *x_max, int x);
void	skip_spaces_line(char *line, int *x, int *flag);
void	skip_spaces_col(char **map, int *y, int x);
void	skip_map_sym_col(char **map, int *y, int x);

/*parsing map*/
int		check_map_ver(char **map, int x_max);
int		make_rect_map(char **map, int x_max);
int		check_one_line(char *line, t_plr *plr_data);
int		check_map_hor(char **map, t_plr *plr_data, int *x_max);
int		check_sym_map(char *line, int *x, t_plr *plr_data);

/*game utils*/

void	my_pixel_put(t_win *win, int x, int y, int color);

int		cub(t_data *all);

int		stop_game(t_data *all);

/*get texture*/
int		start_win(t_data *all);

/*draw*/
void	put_ray(t_win *win, t_crs crs, int w_h, int x);
void	put_screen(t_data *all);

int		key_handle(int key, t_data *all);

/*player movement*/
void	plr_up(char **map, t_plr *plr_data);
void	plr_down(char **map, t_plr *plr_data);
void	plr_left(char **map, t_plr *plr_data);
void	plr_right(char **map, t_plr *plr_data);
void	plr_rot_right(t_plr *plr_data);
void	plr_rot_left(t_plr *plr_data);

int		get_wall_side(t_crs cross, char **map);

//DRAFT VERSION
void	get_crossing(char **map, t_plr *data);
void	get_distance(t_plr *plr_data, int index);
char	wall(char **map, t_plr *data, double *x0, double *y0);
char	fill_correction(t_plr *plr_data, int x_win);
// int		raycast(char **map, t_plr *plr, t_win *win);
// void	put_ray(t_win *win, int w_color, int w_h, int x);

#endif
