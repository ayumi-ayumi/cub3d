/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_extract_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:26:43 by asato             #+#    #+#             */
/*   Updated: 2026/06/02 19:49:50 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "cub3d.h"
#include "parser.h"
#include "libft.h"
#include <unistd.h>

static int	extract_path(t_game *game, char *str, t_direction dir)
{
	int	i;

	i = 2;
	if (ft_strlen(str) < 3)
		return (0);
	while (str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (printf("here\n"), 0);
	game->config.dir_path[dir] = ft_strdup(&str[i]);
	if (!game->config.dir_path[dir])
		return (0);
	return (1);
}

static int	extract_dir_config(t_game *game)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (ft_strncmp(game->file_contents[i], "NO", 2) == 0)
		{
			if (!extract_path(game, game->file_contents[i], DIR_NO))
				return (0);
		}
		if (ft_strncmp(game->file_contents[i], "SO", 2) == 0)
		{
			if (!extract_path(game, game->file_contents[i], DIR_SO))
				return (0);
		}
		if (ft_strncmp(game->file_contents[i], "WE", 2) == 0)
		{
			if (!extract_path(game, game->file_contents[i], DIR_WE))
				return (0);
		}
		if (ft_strncmp(game->file_contents[i], "EA", 2) == 0)
		{
			if (!extract_path(game, game->file_contents[i], DIR_EA))
				return (0);
		}
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
	i = 0; // validate the number is within the range 0-255
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

static int	extract_rgb_config(t_game *game)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if ((ft_strncmp(game->file_contents[i], "F", 1) == 0)
			&& !extract_rgb(game->config.floor, game->file_contents[i]))
			return (0);
		if ((ft_strncmp(game->file_contents[i], "C", 1) == 0)
			&& !extract_rgb(game->config.floor, game->file_contents[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	validate_prefix(t_game *game)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (i < 6)
	{
		if (ft_strncmp(game->file_contents[i], "NO", 2) == 0)
			flag++;
		if (ft_strncmp(game->file_contents[i], "SO", 2) == 0)
			flag++;
		if (ft_strncmp(game->file_contents[i], "WE", 2) == 0)
			flag++;
		if (ft_strncmp(game->file_contents[i], "EA", 2) == 0)
			flag++;
		if (ft_strncmp(game->file_contents[i], "F", 1) == 0)
			flag++;
		if (ft_strncmp(game->file_contents[i], "C", 1) == 0)
			flag++;
		i++;
	}
	if (flag != 6)
		return (0);
	return (1);
}

static void free_dir_parh(char **dir_path_arr)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!dir_path_arr[i])
			i++;
		ft_free((void **)&dir_path_arr[i++]);
	}
	ft_free((void **)&dir_path_arr);
}

static int validate_config(t_game *game)
{
	if (!validate_prefix(game))
		return (0);
	game->config.dir_path = ft_calloc(5, sizeof(char *));
	if (!game->config.dir_path)
		return (0);
	if (!extract_dir_config(game))
		return (free_dir_parh(game->config.dir_path), 0);
	if (!extract_rgb_config(game))
		return (0);
	return (1);
}

int	exract_elements(t_game *game)
{
	if (!validate_config(game))
		return (print_error("Imcopmete config data\n"), 0);
	game->map.height = game->map.height - 6 + 1;
	if (!extract_map(game))
		return (0);
	return (1);
}
