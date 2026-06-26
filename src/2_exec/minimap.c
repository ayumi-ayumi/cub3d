/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asato <asato@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 17:51:57 by asato             #+#    #+#             */
/*   Updated: 2026/06/26 17:54:39 by asato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "exec.h"
#include <math.h>/*for pi*/
#include <mlx.h>

void	img_pix_put(t_data *img, int x, int y, unsigned int color)
{
	char	*pixel;
	int		i;

	if (!img || !img->addr || x < 0 || y < 0)
		return ;
	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_length + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

static int	render_tile(t_game *game, t_tile tile, int size)
{
	int	i;
	int	j;

	i = tile.y;
	while (i < tile.y + size)
	{
		j = tile.x;
		while (j < tile.x + size)
			img_pix_put(&game->exec.scre, j++, i, tile.color);
		++i;
	}
	return (0);
}

static t_pos	convert(t_vec a)
{
	t_pos	result;

	result.col = (int)(a.x * (double)TILE_SIZE);
	result.row = (int)(a.y * (double)TILE_SIZE);
	return (result);
}

static int	find_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

static void	display_fan_beam(t_map map, t_data *screen, t_play play)
{
	double	t;
	t_pos	line;
	t_pos	max;
	t_vec	ray_dir;
	double	angle;
	int		fan_max;

	max.col = map.width * TILE_SIZE;
	max.row = map.height * TILE_SIZE;
	angle = (M_PI / 6) * - 1;
	fan_max = find_max(max.row, max.col);
	play.pos.x += 0.2;
	while (angle < M_PI / 6)
	{
		t = 0.0;
		ray_dir = turn_vec(play.dir, angle);
		while (t <= fan_max)
		{
			line = convert(add_vec(play.pos, mult_vec(t, ray_dir)));
			if (line.col >= max.col || line.row >= max.row || line.col < 0 || line.row < 0
				|| map.grid[line.row / TILE_SIZE][line.col / TILE_SIZE] == '1') //  valid pixel indices go from 0 to max - 1.
				break ;
			img_pix_put(screen, line.col, line.row, FAN_COLOR);
			t += 0.01;
		}
		angle += 0.01;
	}
}

void	draw_minimap(t_game *game)
{
	int		row;
	int		col;
	t_tile	tile;
	t_tile	player;

	tile = (t_tile){0, 0, 0};
	row = 0;
	while (row < game->map.height)
	{
		col = 0;
		while (game->map.grid[row][col] != '\0')
		{
			tile.x = col * TILE_SIZE;
			tile.y = row * TILE_SIZE;
			if (game->map.grid[row][col] == '1')
				tile.color = WALL_COLOR;
			else
				tile.color = FLOOR_COLOR;
			render_tile(game, tile, TILE_SIZE);
			col++;
		}
		if (col < game->map.width)
		{
			while (col < game->map.width)
			{
				tile.x = col * TILE_SIZE;
				tile.color = FLOOR_COLOR;
				render_tile(game, tile, TILE_SIZE);
				col++;
			}
		}
		row++;
	}
	player.x = game->exec.play.pos.x * TILE_SIZE;
	player.y = game->exec.play.pos.y * TILE_SIZE;
	player.color = PLAYER_COLOR;
	render_tile(game, player, PLAYER_SIZE);
	display_fan_beam(game->map, &game->exec.scre, game->exec.play);
}
