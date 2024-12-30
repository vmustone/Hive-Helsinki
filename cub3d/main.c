/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 07:54:05 by vmustone          #+#    #+#             */
/*   Updated: 2024/01/12 15:55:14 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_angle(t_map *map, float angle)
{
	map->angle = angle;
	map->cur_dir.x = cos(angle * M_PI / 180);
	map->cur_dir.y = -sin(angle * M_PI / 180);
}

int	ft_strlen_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	t_map	*game_map;

	if (argc != 2)
		return (printf("wrong input\n"));
	game_map = init_map(argv);
	if (!game_map)
		return (1);
	init_game(game_map);
	return (0);
}
