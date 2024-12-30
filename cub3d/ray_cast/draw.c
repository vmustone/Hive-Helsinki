/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:12:59 by vmustone          #+#    #+#             */
/*   Updated: 2024/01/11 19:46:26 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	vertical(t_map *map, t_ray *ray)
{
	t_fvec	*p;
	float	tane;

	p = &map->cur_pos_u;
	tane = tan(d_to_r(ray->a));
	if (cos(d_to_r(ray->a)) < -PRECISION)
	{
		ray->v_offset.x = -CUBE;
		ray->v_offset.y = -ray->v_offset.x * tane;
		ray->v_map.x = (int)p->x / CUBE * CUBE - PRECISION;
		ray->v_map.y = p->y + ((p->x - ray->v_map.x) * tane);
	}
	else if (cos(d_to_r(ray->a)) > PRECISION)
	{
		ray->v_offset.x = CUBE;
		ray->v_offset.y = -ray->v_offset.x * tane;
		ray->v_map.x = (int)p->x / CUBE * CUBE + CUBE;
		ray->v_map.y = p->y + ((p->x - ray->v_map.x) * tane);
	}
	else
	{
		ray->v_map.x = p->x;
		ray->v_map.y = p->y;
	}
	calc_dist(map, &ray->v_grid, &ray->v_map, &ray->v_offset);
}

static void	horizontal(t_map *map, t_ray *ray)
{
	t_fvec	*p;
	float	cotan;

	p = &map->cur_pos_u;
	cotan = 1.0 / tan(d_to_r(ray->a));
	if (sin(d_to_r(ray->a)) > PRECISION)
	{
		ray->h_offset.y = -CUBE;
		ray->h_offset.x = -ray->h_offset.y * cotan;
		ray->h_map.y = (int)p->y / CUBE * CUBE - PRECISION;
		ray->h_map.x = p->x + ((p->y - ray->h_map.y) * cotan);
	}
	else if (sin(d_to_r(ray->a)) < -PRECISION)
	{
		ray->h_offset.y = CUBE;
		ray->h_offset.x = -ray->h_offset.y * cotan;
		ray->h_map.y = (int)p->y / CUBE * CUBE + CUBE;
		ray->h_map.x = p->x + ((p->y - ray->h_map.y) * cotan);
	}
	else
	{
		ray->h_map.x = p->x;
		ray->h_map.y = p->y;
	}
	calc_dist(map, &ray->h_grid, &ray->h_map, &ray->h_offset);
}

static void	shortest(t_map *map, t_ray *ray)
{
	float	h_dist;
	float	v_dist;

	v_dist = cos(d_to_r(ray->a)) * (ray->v_map.x - map->cur_pos_u.x)
		- sin(d_to_r(ray->a)) * (ray->v_map.y - map->cur_pos_u.y);
	h_dist = cos(d_to_r(ray->a)) * (ray->h_map.x - map->cur_pos_u.x)
		- sin(d_to_r(ray->a)) * (ray->h_map.y - map->cur_pos_u.y);
	if (h_dist != 0.0f && (h_dist <= v_dist || v_dist == 0.0f))
	{
		ray->way = HORIZONTAL;
		ray->dist = h_dist;
	}
	else
	{
		ray->way = VERTICAL;
		ray->dist = v_dist;
	}
}

static void	draw_walls(t_map *map, t_ray *ray)
{
	int	rays_sent;

	rays_sent = 0;
	while (rays_sent <= WIDTH)
	{
		horizontal(map, ray);
		vertical(map, ray);
		shortest(map, ray);
		picture(map, ray, WIDTH - rays_sent);
		ray->a += ray->cast_angle;
		ray->a = correct_angle(ray->a);
		rays_sent++;
	}
}

void	draw(void *p)
{
	t_map	*map;
	t_ray	ray;

	map = p;
	ft_bzero(&ray, sizeof(ray));
	ray.a = correct_angle(map->angle - 25);
	ray.cast_angle = 50 / (float)WIDTH;
	draw_background(map);
	draw_walls(map, &ray);
}
