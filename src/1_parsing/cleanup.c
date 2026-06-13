/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:43:33 by asato             #+#    #+#             */
/*   Updated: 2026/06/13 14:11:20 by lbueno-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <mlx.h>

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


void	cleanup_and_exit(t_game *game)
{
	if (!game)
		return ;
	if (game->map.grid)
		free_map(&game->map);
	if (game->config.dir_path)
		free_string_array(game->config.dir_path);
	free_entire_mlx(game);
	exit (0);
}
