/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_extract_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:26:43 by asato             #+#    #+#             */
/*   Updated: 2026/05/29 19:20:05 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "cub3d.h"
#include "parser.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>

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

static char	*extract_path(t_game *game, char *str, t_direction dir, int *flag)
{
	int	i;

	i = 2;
	while (str[i] == ' ')
		i++;
	(*flag)++;
	if (dir == DIR_NO)
	{
		game->config.no = ft_strdup(&str[i]);
		if (!game->config.no)
			return (NULL);
	}
	if (dir == DIR_SO)
	{
		game->config.so = ft_strdup(&str[i]);
		if (!game->config.so)
			return (NULL);
	}
	if (dir == DIR_WE)
	{
		game->config.we = ft_strdup(&str[i]);
		if (!game->config.we)
			return (NULL);
	}
	if (dir == DIR_EA)
	{
		game->config.ea = ft_strdup(&str[i]);
		if (!game->config.ea)
			return (NULL);
	}
	return (NULL);
}

static int	validate_config(t_game *game, int *i)
{
	int	flag;

	flag = 0;

	while (*i < 6)
	{
		if (ft_strncmp(game->file_contents[*i], "NO", 2) == 0)
			extract_path(game, game->file_contents[*i], DIR_NO, &flag);
		if (ft_strncmp(game->file_contents[*i], "SO", 2) == 0)
			extract_path(game, game->file_contents[*i], DIR_SO, &flag);
		if (ft_strncmp(game->file_contents[*i], "WE", 2) == 0)
			extract_path(game, game->file_contents[*i], DIR_WE, &flag);
		if (ft_strncmp(game->file_contents[*i], "EA", 2) == 0)
			extract_path(game, game->file_contents[*i], DIR_EA, &flag);
		if (ft_strncmp(game->file_contents[*i], "F", 1) == 0
			&& extract_rgb(game->config.floor, game->file_contents[*i]))
			flag++;
		if (ft_strncmp(game->file_contents[*i], "C", 1) == 0
			&& extract_rgb(game->config.ceiling, game->file_contents[*i]))
			flag++;
		(*i)++;
	}
	if (flag != 6)
		return (print_error("Imcopmete config data\n"), 0);
	return (1);
}

int	exract_elements(t_game *game)
{
	int	i;

	i = 0;
	if (!validate_config(game, &i))
		return (0);
	game->map.height = game->map.height - i + 1;
	if (!extract_map(game, &i))
		return (0);
	return (1);
}
