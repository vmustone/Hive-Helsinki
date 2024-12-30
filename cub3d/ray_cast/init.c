/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:12:59 by vmustone          #+#    #+#             */
/*   Updated: 2024/01/12 15:40:59 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static bool	textures_init(t_map *map)
{
	map->north = mlx_load_png(map->no);
	map->south = mlx_load_png(map->so);
	map->east = mlx_load_png(map->ea);
	map->west = mlx_load_png(map->we);
	if (!map->north || !map->south || !map->east || !map->west)
		return (false);
	return (true);
}

int	init_game(t_map *map)
{
	map->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (!map->mlx)
		return (1);
	map->image = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	if (!map->image)
	{
		mlx_close_window(map->mlx);
		exit(1);
	}
	if (mlx_image_to_window(map->mlx, map->image, 0, 0) == -1)
	{
		mlx_close_window(map->mlx);
		exit(1);
	}
	if (!textures_init(map))
	{
		mlx_close_window(map->mlx);
		exit(1);
	}
	mlx_loop_hook(map->mlx, &draw, map);
	mlx_loop_hook(map->mlx, &move, map);
	mlx_loop(map->mlx);
	return (0);
}
