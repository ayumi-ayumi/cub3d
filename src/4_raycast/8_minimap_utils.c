/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_minimap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ayumi <Ayumi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 17:51:57 by asato             #+#    #+#             */
/*   Updated: 2026/06/27 13:40:35 by Ayumi            ###   ########.fr       */
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

void	render_tile(t_game *game, t_tile tile, int size)
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
}

t_pos	convert(t_vec a)
{
	t_pos	result;

	result.col = (int)(a.x * (double)TILE_SIZE);
	result.row = (int)(a.y * (double)TILE_SIZE);
	return (result);
}

int	find_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
