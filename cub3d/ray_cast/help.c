/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:12:59 by vmustone          #+#    #+#             */
/*   Updated: 2024/01/11 17:30:17 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

float	d_to_r(float degree)
{
	return (degree * (M_PI / 180));
}

float	correct_angle(float angle)
{
	if (angle < 0)
		angle += 360;
	else if (angle >= 360)
		angle -= 360;
	return (angle);
}

void	calc_dist(t_map *map, t_fvec *grid, t_fvec *map_u, t_fvec *hd)
{
	int	draw_dist;

	draw_dist = 0;
	if (map_u->x == map->cur_pos_u.x && map_u->y == map->cur_pos_u.y)
		return ;
	while (draw_dist < DRAW_DISTANCE)
	{
		grid->x = (int)map_u->x >> 5;
		grid->y = (int)map_u->y >> 5;
		if (grid->y >= 0 && grid->x >= 0 && grid->x < map->columns && grid->y
			< map->rows && map->map[(int)grid->y][(int)grid->x] == '1')
			break ;
		else
		{
			map_u->x += hd->x;
			map_u->y += hd->y;
			draw_dist++;
		}
	}
}

void	draw_background(t_map *map)
{
	t_vec	vector;

	vector.y = 0;
	while (vector.y < HEIGHT)
	{
		vector.x = 0;
		if (vector.y < HEIGHT / 2)
			while (vector.x < WIDTH)
				mlx_put_pixel(map->image, vector.x++, vector.y,
					map->ceiling_color);
		else
			while (vector.x < WIDTH)
				mlx_put_pixel(map->image, vector.x++, vector.y,
					map->floor_color);
		vector.y++;
	}
}
