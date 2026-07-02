/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_extract_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:26:43 by asato             #+#    #+#             */
/*   Updated: 2026/07/02 17:18:45 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include <stdio.h>

static int	extract_path(t_game *game, char *str, t_direction dir)
{
	int	i;

	i = 2;
	if (ft_strlen(str) < 3)
		return (FAIL);
	while (str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (FAIL);
	game->config.texture_paths[dir] = ft_strdup(&str[i]);
	if (!game->config.texture_paths[dir])
		return (perror("malloc"), FAIL);
	return (SUCCESS);
}

int	extract_texture_config(t_game *game)
{
	int		i;
	char	*line;

	i = 0;
	while (i < 6)
	{
		line = game->file_contents[i];
		if (ft_strncmp(line, "NO", 2) == 0
			&& extract_path(game, line, DIR_NO) == FAIL)
			return (FAIL);
		if (ft_strncmp(line, "SO", 2) == 0
			&& extract_path(game, line, DIR_SO) == FAIL)
			return (FAIL);
		if (ft_strncmp(line, "WE", 2) == 0
			&& extract_path(game, line, DIR_WE) == FAIL)
			return (FAIL);
		if (ft_strncmp(line, "EA", 2) == 0
			&& extract_path(game, line, DIR_EA) == FAIL)
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

static int	extract_rgb(int rgb[3], char *str)
{
	int		i;
	char	**rgb_str;
	int		num;

	i = 2;
	while (str[i] == ' ')
		i++;
	rgb_str = ft_split(&str[i], ',');
	if (!rgb_str)
		return (perror("malloc"), FAIL);
	i = 0;
	while (rgb_str[i])
	{
		if (i >= 3 || !ft_is_all_digit(rgb_str[i]))
			return (free_string_array(rgb_str), FAIL);
		num = 0;
		num = ft_atoi(rgb_str[i]);
		if (num < 0 || num > 255)
			return (free_string_array(rgb_str), FAIL);
		rgb[i] = num;
		i++;
	}
	free_string_array(rgb_str);
	return (SUCCESS);
}

int	extract_rgb_config(t_game *game)
{
	int		i;
	char	*line;

	i = 0;
	while (i < 6)
	{
		line = game->file_contents[i];
		if ((ft_strncmp(line, "F", 1) == 0)
			&& extract_rgb(game->config.floor, line) == FAIL)
			return (FAIL);
		if ((ft_strncmp(line, "C", 1) == 0)
			&& extract_rgb(game->config.ceiling, line) == FAIL)
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

void	free_texture_paths(char **texture_paths_arr)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!texture_paths_arr[i])
			i++;
		ft_free((void **)&texture_paths_arr[i++]);
	}
	ft_free((void **)&texture_paths_arr);
}
