/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:44:22 by vmustone          #+#    #+#             */
/*   Updated: 2024/01/12 15:40:36 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	file_name_check(char *argv)
{
	int			length;
	const char	*extension;

	length = ft_strlen(argv);
	extension = ".cub";
	if (length > 4 && ft_strcmp(argv + length - 4, extension) == 0)
		return (0);
	else
	{
		printf("Invalid map filename\n");
		return (1);
	}
}

static int	parse(char *file, t_map *map)
{
	int		fd;
	t_list	*map_data;

	map_data = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	if (read_map_header(map, fd) || read_map(&map_data, map, fd))
	{
		close(fd);
		ft_lstclear(&map_data, free);
		return (1);
	}
	close(fd);
	if (parse_map(map_data, map))
	{
		ft_lstclear(&map_data, free);
		return (1);
	}
	ft_lstclear(&map_data, free);
	return (0);
}

t_map	*init_map(char **argv)
{
	t_map		*map;

	if (file_name_check(argv[1]))
		return (NULL);
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	ft_bzero(map, sizeof(t_map));
	if (parse(argv[1], map) || validate(map))
	{
		printf("invalid map\n");
		exit(1);
	}
	return (map);
}
