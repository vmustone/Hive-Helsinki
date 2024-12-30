/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:22:10 by vmustone          #+#    #+#             */
/*   Updated: 2024/01/12 14:30:36 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	check_header(t_map *map)
{
	if (!map->no || !map->so || !map->ea || !map->we || !map->floor_color
		|| !map->ceiling_color)
		return (1);
	else
		return (0);
}

static int	map_chars(t_map *map)
{
	char	*chars;
	int		x;
	int		y;

	chars = " 01NWSE\t";
	y = 0;
	if (map->map[y] == NULL)
		return (1);
	while (y < map->rows)
	{
		x = 0;
		while (x < map->columns)
		{
			if (!ft_strchr(chars, map->map[y][x]))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	get_starting_angle(t_map *map, char c)
{
	map->cur_pos_u.x = map->cur_pos.x * (float)CUBE
		+ (((float)CUBE - (float)PLAYER) / 2);
	map->cur_pos_u.y = map->cur_pos.y * (float)CUBE
		+ (((float)CUBE - (float)PLAYER) / 2);
	if (c == 'N')
		get_angle(map, 90.0f);
	else if (c == 'S')
		get_angle(map, 270.0f);
	else if (c == 'W')
		get_angle(map, 180.0f);
	else if (c == 'E')
		get_angle(map, 0.0f);
}

static int	check_walls(t_map *map)
{
	char	*edge;
	int		x;
	int		y;

	edge = save_edge_characters(map);
	if (check_edge_chars(edge))
		return (1);
	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->columns)
		{
			if (map->map[y][x] == ' ')
			{
				if (check_edge_chars(get_surrounding_chars(map, y, x)))
				{
					return (1);
				}
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	validate(t_map *map)
{
	if (check_header(map))
		return (1);
	if (map_chars(map))
		return (1);
	if (num_of_players(map) != 1)
		return (1);
	if (check_walls(map))
		return (1);
	if (map->rows > 120 || map->columns > 120)
	{
		printf("Map too big\n");
		exit(1);
	}
	return (0);
}
