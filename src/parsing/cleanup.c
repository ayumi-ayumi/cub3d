/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:43:33 by asato             #+#    #+#             */
/*   Updated: 2026/05/25 17:43:34 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "cub3d.h"
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

void	free_mlx_img(t_game *game, void **target)
{
	if (!game || !game->mlx || !target || !*target)
		return ;
	mlx_destroy_image(game->mlx, *target);
	*target = NULL;
}

void	free_mlx(t_game *game)
{
	if (game->mlx)
	{
		free_mlx_img(game, (void **)&game->texture.player_up);
		free_mlx_img(game, (void **)&game->texture.player_right);
		free_mlx_img(game, (void **)&game->texture.player_down);
		free_mlx_img(game, (void **)&game->texture.player_left);
		free_mlx_img(game, (void **)&game->texture.floor);
		// free_mlx_img(game, (void **)&game->texture.exit);
		// free_mlx_img(game, (void **)&game->texture.exit_open);
		free_mlx_img(game, (void **)&game->texture.wall);
		// free_mlx_img(game, (void **)&game->texture.collectible);
		if (game->win)
		{
			mlx_destroy_window(game->mlx, game->win);
			game->win = NULL;
		}
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
}

void	cleanup_and_exit(t_game *game)
{
	if (!game)
		return ;
	if (game->map.grid)
		free_map(&game->map);
	// free_mlx(game);

	exit (0);
}
