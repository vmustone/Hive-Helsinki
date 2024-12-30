/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_and_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:16:44 by vmustone          #+#    #+#             */
/*   Updated: 2024/01/12 15:32:14 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	parse_compass_point(t_map *map, char *line)
{
	int	ret;

	ret = 0;
	if (ft_strncmp(line, "NO ", 3) == 0 && map->no == NULL)
		ret = remove_spaces_check_commas(line, 3, &map->no, 0);
	else if (ft_strncmp(line, "SO ", 3) == 0 && map->so == NULL)
		ret = remove_spaces_check_commas(line, 3, &map->so, 0);
	else if (ft_strncmp(line, "WE ", 3) == 0 && map->we == NULL)
		ret = remove_spaces_check_commas(line, 3, &map->we, 0);
	else if (ft_strncmp(line, "EA ", 3) == 0 && map->ea == NULL)
		ret = remove_spaces_check_commas(line, 3, &map->ea, 0);
	else
		return (2);
	return (ret);
}

int	parse_header(t_map *map, char *line)
{
	int	i;
	int	check;

	i = ft_strlen(line);
	line[i - 1] = '\0';
	check = parse_compass_point(map, line);
	if (check == 2 && ft_strncmp(line, "F ", 2) == 0)
	{
		if (rgb_string_to_int(line, &map->floor_color))
			return (1);
	}
	else if (check == 2 && ft_strncmp(line, "C ", 2) == 0)
	{
		if (rgb_string_to_int(line, &map->ceiling_color))
			return (1);
	}
	else if (check == 2 || check == 1)
		return (1);
	free(line);
	return (0);
}

int	read_map_header(t_map *map, int fd)
{
	char	*line;
	int		rows;

	rows = 0;
	while (rows < 6)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		if (ft_strlen(line) == 1)
		{
			free(line);
			continue ;
		}
		if (parse_header(map, line))
		{
			free(line);
			return (1);
		}
		rows++;
	}
	return (0);
}

int	read_map(t_list **map_info, t_map *map, int fd)
{
	char	*line;
	t_list	*lst;

	map->rows = 0;
	line = get_next_line(fd);
	while (line && ft_strlen(line) == 1)
	{
		free(line);
		line = get_next_line(fd);
	}
	while (line)
	{
		lst = ft_lstnew(line);
		if (!lst)
		{
			free(line);
			return (1);
		}
		ft_lstadd_back(map_info, lst);
		map->rows++;
		line = get_next_line(fd);
	}
	return (0);
}
