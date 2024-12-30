/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:00:42 by vmustone          #+#    #+#             */
/*   Updated: 2024/01/12 15:42:46 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static int	isnumeric(const char *str)
{
	if (*str == '-')
		return (1);
	if (*str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (1);
		str++;
	}
	return (0);
}

static void	rgb_to_int(char **rgb_array, int *save)
{
	int	rgb[3];
	int	i;

	i = 0;
	while (i < 3)
	{
		if (isnumeric(rgb_array[i]))
			return ;
		rgb[i] = ft_atoi(rgb_array[i]);
		if (rgb[i] > 255 || rgb < 0)
			return ;
		i++;
	}
	*save = rgb[0] << 24 | rgb[1] << 16 | rgb[2] << 8 | 255;
}

int	remove_spaces_check_commas(char *line, int len, char **save, int flag)
{
	int	i;
	int	commas;

	i = 0;
	commas = 0;
	line += len;
	if (line[ft_strlen(line) - 1] == ' ' || line[ft_strlen(line) - 1] == '\t')
		return (1);
	while (*line == ' ')
		line++;
	while (line[i] && flag == 1)
	{
		if (line[i] == ',')
			commas++;
		i++;
	}
	if (commas != 2 && flag == 1)
		return (1);
	*save = ft_substr(line, 0, ft_strlen(line));
	return (0);
}

int	rgb_string_to_int(char *input, int *save)
{
	char	*str;
	char	**nbr;

	str = NULL;
	if (remove_spaces_check_commas(input, 2, &str, 1))
		return (1);
	if (!str)
		return (1);
	nbr = ft_split(str, ',');
	if (ft_strlen_array(nbr) != 3)
	{
		free_str(nbr);
		free(str);
		return (1);
	}
	free(str);
	if (!nbr)
	{
		free_str(nbr);
		return (1);
	}
	rgb_to_int(nbr, save);
	free_str(nbr);
	return (0);
}
