/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_validate_elements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:26:43 by asato             #+#    #+#             */
/*   Updated: 2026/07/02 17:09:09 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include <stdio.h>

static int	validate_prefix(t_game *game)
{
	int	i;
	int	found;

	i = 0;
	found = 0;
	while (i < 6)
	{
		if (ft_strncmp(game->file_contents[i], "NO", 2) == 0)
			found++;
		if (ft_strncmp(game->file_contents[i], "SO", 2) == 0)
			found++;
		if (ft_strncmp(game->file_contents[i], "WE", 2) == 0)
			found++;
		if (ft_strncmp(game->file_contents[i], "EA", 2) == 0)
			found++;
		if (ft_strncmp(game->file_contents[i], "F ", 2) == 0)
			found++;
		if (ft_strncmp(game->file_contents[i], "C ", 2) == 0)
			found++;
		i++;
	}
	if (found != 6)
		return (FAIL);
	return (SUCCESS);
}

static int	trim_space_in_line(t_game *game)
{
	int		i;
	char	*temp;

	i = 0;
	while (i < 6)
	{
		temp = ft_strtrim(game->file_contents[i], " ");
		if (!temp)
			return (perror("malloc"), FAIL);
		free(game->file_contents[i]);
		game->file_contents[i] = temp;
		if (!game->file_contents[i])
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

static int	validate_config_set(t_game *game)
{
	if (game->file_contents[6][0] != ' ' && game->file_contents[6][0] != '1')
		return (print_error("The config lines are incorrect"), FAIL);
	return (SUCCESS);
}

static int	validate_config(t_game *game)
{
	if (trim_space_in_line(game) == FAIL)
		return (FAIL);
	if (validate_prefix(game) == FAIL)
		return (FAIL);
	game->config.texture_paths = ft_calloc(5, sizeof(char *));
	if (!game->config.texture_paths)
		return (perror("malloc"), FAIL);
	if (extract_texture_config(game) == FAIL)
		return (free_texture_paths(game->config.texture_paths), FAIL);
	if (extract_rgb_config(game) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

int	extract_elements(t_game *game)
{
	if (validate_config_set(game) == FAIL)
		return (FAIL);
	if (validate_config(game) == FAIL)
		return (print_error("Incomplete config data"), FAIL);
	game->map.height = game->map.height - 6 + 1;
	if (extract_map(game) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
