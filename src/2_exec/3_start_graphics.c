/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_start_graphics.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 15:19:26 by asato             #+#    #+#             */
/*   Updated: 2026/06/22 18:38:55 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3d.h"
#include "exec.h"
#include <mlx.h>
#include <math.h>/*for M_PI_2*/

int	close_window(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	free_entire_mlx(game);
	cleanup_and_exit(game);
	return (1);
}

int	draw(t_game *game, t_data *scre)
{
	t_play	*play;

	play = &game->exec.play;
	play->plane = turn_vec(play->dir, -1 * M_PI_2);
	raycast(game, &game->exec);
	mlx_put_image_to_window(game->mlx, game->win, scre->img, 0, 0);
	return (SUCCESS);
}

int	start_graphics(t_game *game)
{
	if (!game || !game->mlx || !game->win)
		return (FAIL);
	draw(game, &game->exec.scre);
	mlx_hook(game->win, 2, 1L << 0, key_hook, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop(game->mlx);
	return (SUCCESS);
}
