// #include "cub3d.h"
#include "exec.h"
#include <mlx.h>

// #define WALL_COLOR    0xFF0000  // グレー（壁）
#define WALL_COLOR    0x333333  // グレー（壁）
#define FLOOR_COLOR   0xCCCCCC  // 薄いグレー（床）
#define PLAYER_COLOR  0xFF0000  // 赤（プレイヤー）

typedef struct s_tile
{
    int	x;
    int	y;
    int width;
    int height;
    int color;
}	t_tile;

void	img_pix_put(t_data *img, int x, int y, int color)
{
    char    *pixel;
	int	i;

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

void	render_margin(t_game *game)
{
	t_tile	tile;
	int		size;
	int		i;


	size = 10;
	tile = (t_tile){0, 0, size, size, 0};
	i = 0;
	while (i < game->map.width + 2)
	{
		tile.x = i * size + 10;
		tile.y = 10;
		tile.color = FLOOR_COLOR;
		render_tile(game, tile);
		i++;
	}
}

void	draw_minimap(t_game *game)
{
	int	row;
	int	col;
	int size = 10;
	t_tile tile;

	tile = (t_tile){0, 0, size, size, 0};
	row = 0;
	render_margin(game);
	while (row < game->map.height)
	{
		col = 0;
		while (game->map.grid[row][col] != '\0')
		{
			tile.x = col * size + 20; // margin 20pixels
			tile.y = row * size + 20; // margin 20pixels

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
				tile.x = col * size + 20; // margin 20pixels
				tile.color = FLOOR_COLOR;
				render_tile(game, tile);
				col++;
			}
		}
		row++;
	}
}

void	minimap(t_game *game)
{
	draw_minimap(game);
}
