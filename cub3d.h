/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 20:50:39 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/03 14:52:20 by dselmy           ###   ########.fr       */
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

/* for checking if anything is missing from the scene description file*/

# define SCALE 16

# define NO_TEX 0
# define SO_TEX 1
# define WE_TEX 2
# define EA_TEX 3
// # define SP_TEX 5 (only for bonuses)
# define FLOOR_COL 4
# define CEIL_COL 5
# define MAP 6

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


//delete later
# define WALL_EA_WE 0x7E1A35
# define WALL_SO_NO 0x9F2042
# define COLOR_NO 0x000000FF
# define COLOR_SO 0x00FF0000
# define COLOR_EA 0x0000FF00
# define COLOR_WE 0x00FFFF00

typedef struct s_img
{
	void		*img;
	void		*addr;
	int			line_len;
	int			bpp;
	int			en;
	int			height;
	int			width;
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
	t_img		no_tex;
	t_img		so_tex;
	t_img		ea_tex;
	t_img		we_tex;
	t_img		spr_tex;
}				t_win;

typedef struct	s_config
{
	int			data[7]; // make it into identifiers order
	int			x_res;
	int			y_res;
	int			s_key;
	char		*no_tex_path;
	char		*so_tex_path;
	char		*ea_tex_path;
	char		*we_tex_path;
	// char		*spr_tex_path; for bonus
	int			ceil_color;
	int			floor_color;
}				t_config;

typedef struct	s_plr
{
	int			plr_num;
	double		plr_pos_x;
	double		plr_pos_y;
	double		plr_dir_rad;
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

void	check_arg(int argc, char **argv, t_data *all);
int		check_file_format(char *file_name, char *format);
int		only_num(const char *line);
void	free_arr(char **arr);
int		set_flag(int *flag);
int		create_trgb(int t, int r, int g, int b);

void	shut_down(t_data *all, int error);
void	free_all(t_data *all);
void	manage_config_errors(int error);
void	manage_arg_errors(int error);
void	free_config(t_data *all);

int		make_map_arr(t_data *all, t_list **map_ptr, int map_h);
int		read_config(int fd, t_list **head);
int		parse_config(t_data *all, t_list *cnfg_lst);
int		parse_map(t_data *all, t_list **map_ptr);
void	parser(t_data *all);

/*parse config*/
int		check_identifiers(int id_number, t_config *cnfg, char *line);
int		parse_color(int	*color, char *line, int *flag);
int		parse_tex_pth(char **tex_path, char *line, int *flag);
int		parse_resolution(char *line, t_config *cnfg, int *flag);
void	check_all_data(t_data *all);
char	*get_identifier(int id_number);

int		parse_color_end(char **array, char *line_wo_spaces, int error);
int		parse_res_end(char **array, int error);

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
int		get_texture(t_win *win, t_config *cnfg);

/*draw*/
void	put_ray(t_win *win, int w_color, int w_h, int x);

/*player movement*/
void	plr_up(char **map, t_plr *plr_data);
void	plr_down(char **map, t_plr *plr_data);
void	plr_left(char **map, t_plr *plr_data);
void	plr_right(char **map, t_plr *plr_data);
void	plr_rot_right(t_plr *plr_data);
void	plr_rot_left(t_plr *plr_data);

int	get_wall_side(float y, float x, float ray_dir, char **map);

//DRAFT VERSION
int		raycast(char **map, t_plr *plr, t_win *win);
// void	put_ray(t_win *win, int w_color, int w_h, int x);

#endif