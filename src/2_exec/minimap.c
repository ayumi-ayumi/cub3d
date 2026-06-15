// #include "cub3d.h"
#include "exec.h"
#include <mlx.h>

#define WALL_COLOR    0xFF0000  // グレー（壁）
// #define WALL_COLOR    0x333333  // グレー（壁）
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

int	render_rect(t_game *game, t_tile tile)
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
			mlx_pixel_put(game->mlx, game->win, j++, i, tile.color);
		++i;
	}
	return (0);
}

void	draw_minimap(t_game *game)
{
	int	row;
	int	col;
	int size = 10;

	row = 0;
	while (row < game->map.height)
	{
		col = 0;
		while (game->map.grid[row][col] != '\0')
		{
			t_tile tile;
			tile.x = col * size + 20; // margin 20pixels
			tile.y = row * size + 20; // margin 20pixels
			tile.width = size;
			tile.height = size;

			if (game->map.grid[row][col] == '1')
				tile.color = WALL_COLOR;
			else
				tile.color = FLOOR_COLOR;

			render_rect(game, tile);
			col++;
		}
		row++;
	}
}

void	minimap(t_game *game)
{
	draw_minimap(game);
}
