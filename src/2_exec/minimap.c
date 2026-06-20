// #include "cub3d.h"
#include "exec.h"
#include <mlx.h>
#include <math.h>

void	img_pix_put(t_data *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

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

int	render_tile(t_game *game, t_tile tile)
{
	int	i;
	int	j;

	if (game->win == NULL)
		return (1);
	i = tile.y;
	while (i < tile.y + tile.height)
	{
		j = tile.x;
		while (j < tile.x + tile.width)
			img_pix_put(&game->exec.scre, j++, i, tile.color);
		++i;
	}
	return (0);
}

static t_pos	convert(t_vec a)
{
	t_pos	result;

	result.col = (int)(a.x * (double)MINI);
	result.row = (int)(a.y * (double)MINI);
	return (result);
}

static void	put_dir(t_map map, t_data *screen, t_play play)
{
	double	t;
	t_pos	pixel;
	t_pos	max;

	t = 0.0;
	max.col = map.width * MINI;
	max.row = map.height * MINI;
	while (t <= 2.0)
	{
		pixel = convert(add_vec(play.pos, mult_vec(t, play.dir)));
		if (pixel.col > max.col || pixel.row >  max.row || pixel.col < 0 || pixel.row < 0)
			break;
		img_pix_put(screen, pixel.col, pixel.row, 0xFFFFFF);
		t += 0.01;
	}
}

void	draw_minimap(t_game *game)
{
	int		row;
	int		col;
	int		size;
	t_tile	tile;
	t_tile	player;

	size = 10;
	tile = (t_tile){0, 0, size, size, 0};
	row = 0;
	while (row < game->map.height)
	{
		col = 0;
		while (game->map.grid[row][col] != '\0')
		{
			tile.x = col * size;
			tile.y = row * size;

			if (game->map.grid[row][col] == '1')
				tile.color = WALL_COLOR;
			else
				tile.color = FLOOR_COLOR;
			render_tile(game, tile);

			col++;
		}
		if (col < game->map.width)
		{
			while (col < game->map.width)
			{
				tile.x = col * size;
				tile.color = FLOOR_COLOR;
				render_tile(game, tile);
				col++;
			}
		}
		row++;
	}
	player.x = game->exec.play.pos.x * size;
	player.y = game->exec.play.pos.y * size;
	player.width = 4;
	player.height = 4;
	player.color = PLAYER_COLOR;
	render_tile(game, player);
	put_dir(game->map, &game->exec.scre, game->exec.play);
}
