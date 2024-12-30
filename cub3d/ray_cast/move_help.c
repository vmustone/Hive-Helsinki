/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:12:59 by vmustone          #+#    #+#             */
/*   Updated: 2024/01/10 16:33:24 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_left(t_map	*map)
{
	float	x;
	float	y;

	x = map->cur_dir.y * MS;
	y = -map->cur_dir.x * MS;
	if (can_move(map, map->cur_pos_u.x + x, map->cur_pos_u.y + y))
	{
		map->cur_pos_u.x += x;
		map->cur_pos_u.y += y;
	}
}

void	move_right(t_map *map)
{
	float	x;
	float	y;

	x = -map->cur_dir.y * MS;
	y = map->cur_dir.x * MS;
	if (can_move(map, map->cur_pos_u.x + x, map->cur_pos_u.y + y))
	{
		map->cur_pos_u.x += x;
		map->cur_pos_u.y += y;
	}
}

void	move_down(t_map *map)
{
	float	x;
	float	y;

	x = map->cur_pos_u.x - map->cur_dir.x * MS;
	y = map->cur_pos_u.y - map->cur_dir.y * MS;
	if (can_move(map, x, y))
	{
		map->cur_pos_u.x = x;
		map->cur_pos_u.y = y;
	}
}

void	move_up(t_map *map)
{
	float	x;
	float	y;

	x = map->cur_pos_u.x + map->cur_dir.x * MS;
	y = map->cur_pos_u.y + map->cur_dir.y * MS;
	if (can_move(map, x, y))
	{
		map->cur_pos_u.x = x;
		map->cur_pos_u.y = y;
	}
}
