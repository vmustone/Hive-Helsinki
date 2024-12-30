/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:12:59 by vmustone          #+#    #+#             */
/*   Updated: 2024/01/12 15:43:08 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <string.h>

# define WIDTH 1280
# define HEIGHT 960
# define CUBE 32
# define PLAYER 2
# define MS 3
# define N 1
# define S 2
# define W 3
# define E 4
# define PRECISION 0.0001
# define VERTICAL 1
# define HORIZONTAL 2
# define DRAW_DISTANCE 200

typedef struct s_player
{
	int	pos_x;
	int	pos_y;
}				t_player;

typedef struct s_fvec
{
	double	x;
	double	y;
}				t_fvec;

typedef struct s_vec
{
	int	x;
	int	y;
}				t_vec;

typedef struct s_ray
{
	int		way;
	double	a;
	double	cast_angle;
	double	dist;
	t_fvec	h_map;
	t_fvec	h_grid;
	t_fvec	h_offset;
	t_fvec	v_map;
	t_fvec	v_grid;
	t_fvec	v_offset;
	t_fvec	map;

}				t_ray;

typedef struct s_map
{
	char			**map;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	int				rows;
	int				columns;
	int				floor_color;
	int				ceiling_color;
	float			angle;
	t_vec			cur_pos;
	t_fvec			cur_pos_u;
	t_fvec			cur_dir;
	t_fvec			plane;
	mlx_t			*mlx;
	mlx_image_t		*image;
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*east;
	mlx_texture_t	*west;
}				t_map;

// *---------------------------*
// |      map validation       |
// *---------------------------*

int		num_of_players(t_map *map);
t_map	*init_map(char **argv);
int		read_map_header(t_map *map, int fd);
int		read_map(t_list **map_info, t_map *map, int fd);
int		validate(t_map *map);
char	*get_surrounding_chars(t_map *map, int y, int x);
int		check_edge_chars(char *str);
char	*save_edge_characters(t_map *map);
int		parse_map(t_list *map_data, t_map *map);
int		rgb_string_to_int(char *input, int *save);
int		remove_spaces_check_commas(char *line, int len, char **save, int flag);
void	get_starting_angle(t_map *map, char c);
void	get_angle(t_map *map, float angle);
int		ft_strlen_array(char **str);

// *---------------------------*
// |        ray casting        |
// *---------------------------*
//     static funcs not shown

// init.c
int		init_game(t_map *map);

// draw3d.c
void	draw(void *p);

// draw3d_picture.c
void	picture(t_map *map, t_ray *ray, int x);

// help.c
int		get_rgba(int r, int g, int b, int a);
float	d_to_r(float degree);
float	correct_angle(float angle);
void	calc_dist(t_map *map, t_fvec *h_grid, t_fvec *h_map, t_fvec *hd);
void	draw_background(t_map *map);

// move.c
void	move(void *p);
bool	can_move(t_map *map, float x, float y);

// move_help.c
void	move_left(t_map	*map);
void	move_right(t_map *map);
void	move_down(t_map *map);
void	move_up(t_map *map);

#endif
