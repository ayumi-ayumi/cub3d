/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_validate_elements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:26:43 by asato             #+#    #+#             */
/*   Updated: 2026/06/30 18:47:26 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

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
		return (0);
	return (1);
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
			return (0);
		free(game->file_contents[i]);
		game->file_contents[i] = temp;
		if (!game->file_contents[i])
			return (0);
		i++;
	}
	return (1);
}

static int	validate_config(t_game *game)
{
	if (!trim_space_in_line(game))
		return (0);
	if (!validate_prefix(game))
		return (0);
	game->config.texture_paths = ft_calloc(5, sizeof(char *));
	if (!game->config.texture_paths)
		return (0);
	if (!extract_texture_config(game))
		return (free_texture_paths(game->config.texture_paths), 0);
	if (!extract_rgb_config(game))
		return (0);
	return (1);
}

int	extract_elements(t_game *game)
{
	if (!validate_config(game))
		return (print_error("Incomplete config data\n"), 0);
	game->map.height = game->map.height - 6 + 1;
	if (!extract_map(game))
		return (0);
	return (1);
}
