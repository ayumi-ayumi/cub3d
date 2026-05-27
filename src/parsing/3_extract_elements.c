/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_extract_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:26:43 by asato             #+#    #+#             */
/*   Updated: 2026/05/27 20:42:55 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "cub3d.h"
#include "parser.h"
#include "libft.h"
#include <unistd.h>

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

static char	*extract_path(char *str, int *flag)
{
	int	i;

	i = 2;
	while (str[i] == ' ')
		i++;
	(*flag)++;
	return (&str[i]);
}

static int	validate_config(t_game *game, int *i)
{
	int	flag;

	flag = 0;
	while (*i < 6)
	{
		if (ft_strncmp(game->file_contents[*i], "NO", 2) == 0)
			game->config.no = extract_path(game->file_contents[*i], &flag);
		if (ft_strncmp(game->file_contents[*i], "SO", 2) == 0)
			game->config.so = extract_path(game->file_contents[*i], &flag);
		if (ft_strncmp(game->file_contents[*i], "WE", 2) == 0)
			game->config.we = extract_path(game->file_contents[*i], &flag);
		if (ft_strncmp(game->file_contents[*i], "EA", 2) == 0)
			game->config.ea = extract_path(game->file_contents[*i], &flag);
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
