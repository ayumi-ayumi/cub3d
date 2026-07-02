/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:43:33 by asato             #+#    #+#             */
/*   Updated: 2026/07/02 17:50:51 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"
#include "libft.h"

void	free_string_array(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
			ft_free((void **)&arr[i++]);
		ft_free((void **)&arr);
	}
}

void	free_map(t_map *map)
{
	int	i;

	if (!map || !map->grid)
		return ;
	i = 0;
	while (i < map->height && map->grid[i])
	{
		ft_free((void **)&map->grid[i]);
		i++;
	}
	ft_free((void **)&map->grid);
}

void	cleanup_and_exit(t_game *game, int exit_code)
{
	if (!game)
		return ;
	if (game->map.grid)
		free_map(&game->map);
	if (game->config.texture_paths)
		free_string_array(game->config.texture_paths);
	if (exit_code)
		exit (1);
	exit(0);
}
