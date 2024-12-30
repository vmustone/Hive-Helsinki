/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:12:59 by vmustone          #+#    #+#             */
/*   Updated: 2024/01/10 16:30:51 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	can_move(t_map *map, float x, float y)
{
	int	x_pos;
	int	y_pos;

	x_pos = x / CUBE;
	y_pos = y / CUBE;
	if (map->map[y_pos][x_pos] == '1')
		return (false);
	return (true);
}

static void	turn_player(t_map *map, int keycode)
{
	if (keycode == MLX_KEY_LEFT)
		map->angle = correct_angle(map->angle + 3);
	else if (keycode == MLX_KEY_RIGHT)
		map->angle = correct_angle(map->angle - 3);
	map->cur_dir.x = cos(d_to_r(map->angle));
	map->cur_dir.y = -sin(d_to_r(map->angle));
}

void	move(void *p)
{
	t_map	*map;

	map = p;
	if (mlx_is_key_down(map->mlx, MLX_KEY_W))
		move_up(map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_S))
		move_down(map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_A))
		move_left(map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_D))
		move_right(map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT))
		turn_player(map, MLX_KEY_LEFT);
	if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
		turn_player(map, MLX_KEY_RIGHT);
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE)
		|| mlx_is_key_down(map->mlx, MLX_KEY_Q))
		exit(0);
}
