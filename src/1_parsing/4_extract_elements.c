/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_extract_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:26:43 by asato             #+#    #+#             */
/*   Updated: 2026/06/30 18:47:32 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

static int	extract_path(t_game *game, char *str, t_direction dir)
{
	int	i;

	i = 2;
	if (ft_strlen(str) < 3)
		return (0);
	while (str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (0);
	game->config.texture_paths[dir] = ft_strdup(&str[i]);
	if (!game->config.texture_paths[dir])
		return (0);
	return (1);
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
			&& !extract_path(game, line, DIR_NO))
			return (0);
		if (ft_strncmp(line, "SO", 2) == 0
			&& !extract_path(game, line, DIR_SO))
			return (0);
		if (ft_strncmp(line, "WE", 2) == 0
			&& !extract_path(game, line, DIR_WE))
			return (0);
		if (ft_strncmp(line, "EA", 2) == 0
			&& !extract_path(game, line, DIR_EA))
			return (0);
		i++;
	}
	return (1);
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
		return (0);
	i = 0;
	while (rgb_str[i])
	{
		if (i >= 3)
			return (free_string_array(rgb_str), 0);
		num = 0;
		num = ft_atoi(rgb_str[i]);
		if (num < 0 || num > 255)
			return (free_string_array(rgb_str), 0);
		rgb[i] = num;
		i++;
	}
	free_string_array(rgb_str);
	return (1);
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
			&& !extract_rgb(game->config.floor, line))
			return (0);
		if ((ft_strncmp(line, "C", 1) == 0)
			&& !extract_rgb(game->config.ceiling, line))
			return (0);
		i++;
	}
	return (1);
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
