/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_extract_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:28:05 by asato             #+#    #+#             */
/*   Updated: 2026/06/30 18:47:09 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

static int	store_map_grid(t_game *game, char *line, int i)
{
	game->map.grid[i] = ft_strdup(line);
	if (!game->map.grid[i])
		return (0);
	return (1);
}

int	extract_map(t_game *game)
{
	int	row_idx;
	int	i;

	row_idx = 0;
	i = 6;
	if (game->file_contents[i][0] == '1' || game->file_contents[i][0] == ' ')
	{
		game->map.grid
			= malloc(sizeof(game->map.grid) * (game->map.height + 1));
		if (!game->map.grid)
			return (0);
		while (game->file_contents[i] != NULL)
		{
			if (!store_map_grid(game, game->file_contents[i], row_idx))
				return (0);
			i++;
			row_idx++;
		}
		game->map.grid[row_idx] = NULL;
	}
	return (1);
}
