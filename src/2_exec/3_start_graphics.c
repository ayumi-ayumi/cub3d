/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_start_graphics.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 15:19:26 by asato             #+#    #+#             */
/*   Updated: 2026/06/16 16:13:22 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3d.h"
#include "exec.h"
#include <mlx.h>

// void	draw_tile(t_game *game, int row, int col)
// {
// 	void	**texture;
// 	char	tile;

// 	texture = game->exec.dir_texture;
// 	tile = game->map.grid[row][col];
// 	if (tile == '1')
// 		mlx_put_image_to_window(game->mlx, game->win,
// 			texture[3], col * TEXTURE_WIDTH, row * TEXTURE_HEIGHT);
// 	if (tile == '0')
// 		mlx_put_image_to_window(game->mlx, game->win,
// 			texture[1], col * TEXTURE_WIDTH, row * TEXTURE_HEIGHT);
// }

// void	render_map(t_game *game)
// {
// 	int	row;
// 	int	col;

// 	row = 0;
// 	while (row < game->map.height)
// 	{
// 		col = 0;
// 		while (col < game->map.width)
// 		{
// 			draw_tile(game, row, col);
// 			col++;
// 		}
// 		row++;
// 	}
// }


int	close_window(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	free_entire_mlx(game);
	cleanup_and_exit(game);
	return (1);
}

int	start_graphics(t_game *game)
{
	if (!game || !game->mlx || !game->win)
		return (FAIL);
	// if (!game->exec.dir_texture)//this is causing a segv
	// 	return (FAIL);
	draw(game, &game->exec.play.move,&game->exec.scre);
	// minimap(game);
	mlx_hook(game->win, 2, 1L << 0, key_hook, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop(game->mlx);
	return (SUCCESS);
}
