/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_picture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:12:59 by vmustone          #+#    #+#             */
/*   Updated: 2024/01/12 14:43:14 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static t_fvec	get_texture(t_fvec *hit_cord, int direction, float ys,
	float line_size)
{
	t_fvec	texture;

	texture.y = 0;
	if (line_size > HEIGHT)
		texture.y = fmax(0, (line_size - HEIGHT) / 2.0f) * ys;
	if (direction == N)
		texture.x = CUBE - 1 - (((int)hit_cord->x) % CUBE);
	else if (direction == S)
		texture.x = ((int)hit_cord->x) % CUBE;
	else if (direction == E)
		texture.x = CUBE - 1 - (((int)hit_cord->y) % CUBE);
	else
		texture.x = ((int)hit_cord->y) % CUBE;
	return (texture);
}

static unsigned int	get_color(mlx_texture_t *img, unsigned int x,
	unsigned int y)
{
	unsigned int	color;
	char			*a;

	a = (char *)(img->pixels + (x + (y * img->width)) * 4);
	color = *(unsigned int *)a;
	return (get_rgba(color >> 0 & 0xff, color >> 8 & 0xff,
			color >> 16 & 0xff, 255));
}

static unsigned int	get_pixel(t_map *map, int x, int y, int direction)
{
	unsigned int		color;
	mlx_texture_t		*texture;

	texture = NULL;
	color = 0;
	if (direction == N)
		texture = map->north;
	else if (direction == E)
		texture = map->east;
	else if (direction == S)
		texture = map->south;
	else if (direction == W)
		texture = map->west;
	if (texture)
		color = get_color(texture, x, y);
	return (color);
}

static void	show_picture(t_map *map, t_ray *ray, int x, int direction)
{
	float			lh;
	float			ys;
	t_fvec			texture;
	unsigned int	color;
	int				drawn_count;

	drawn_count = 0;
	ray->dist = ray->dist * cos(d_to_r((ray->a - map->angle)));
	lh = HEIGHT / ray->dist * CUBE;
	ys = CUBE / lh;
	texture = get_texture(&ray->map, direction, ys, lh);
	if (lh > HEIGHT)
		lh = HEIGHT;
	while (drawn_count < lh - 1)
	{
		color = get_pixel(map, texture.x, texture.y, direction);
		mlx_put_pixel(map->image, x, (HEIGHT - lh) / 2 + drawn_count++, color);
		texture.y += ys;
	}
}

void	picture(t_map *map, t_ray *ray, int x)
{
	int	direction;

	direction = 0;
	if (ray->way == HORIZONTAL && (ray->a >= 0 && ray->a < 180))
	{
		direction = N;
		ray->map = ray->h_map;
	}
	else if (ray->way == HORIZONTAL && (ray->a >= 180 && ray->a < 360))
	{
		direction = S;
		ray->map = ray->h_map;
	}
	else if (ray->way == VERTICAL && (ray->a >= 90 && ray->a < 270))
	{
		direction = W;
		ray->map = ray->v_map;
	}
	else if (ray->way == VERTICAL && (ray->a >= 270 || ray->a < 90))
	{
		direction = E;
		ray->map = ray->v_map;
	}
	show_picture(map, ray, x, direction);
}
