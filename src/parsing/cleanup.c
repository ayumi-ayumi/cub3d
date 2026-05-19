//#include "cub3d.h"
#include "parser.h"
#include <unistd.h>
#include <stdlib.h>
#include <mlx.h>

void	free_map(t_cub *map)
{
	int	i;

	if (!map || !map->grid)
		return ;
	i = 0;
	while (i < map->height && map->grid[i])
	{
		free(map->grid[i]);
		map->grid[i] = NULL;
		i++;
	}
	free(map->grid);
	map->grid = NULL;
	map->height = 0;
}

void	free_mlx_img(t_vars *game, void **target)
{
	if (!game || !game->mlx || !target || !*target)
		return ;
	mlx_destroy_image(game->mlx, *target);
	*target = NULL;
}

void	free_mlx(t_vars *game)
{
	if (game->mlx)
	{
		free_mlx_img(game, (void **)&game->img.player_up);
		free_mlx_img(game, (void **)&game->img.player_right);
		free_mlx_img(game, (void **)&game->img.player_down);
		free_mlx_img(game, (void **)&game->img.player_left);
		free_mlx_img(game, (void **)&game->img.floor);
		free_mlx_img(game, (void **)&game->img.exit);
		free_mlx_img(game, (void **)&game->img.exit_open);
		free_mlx_img(game, (void **)&game->img.wall);
		free_mlx_img(game, (void **)&game->img.collectible);
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

void	cleanup_and_exit(t_vars *game)
{
	if (!game)
		return ;
	free_mlx(game);
	if (game->map)
	{
		free_map(game->map);
		if (game->map->map_path)
			free(game->map->map_path);
		game->map = NULL;
	}
	if (game->copy)
	{
		free_map(game->copy);
		if (game->copy->map_path)
			free(game->copy->map_path);
		game->copy = NULL;
	}
	if (game->dfs_stack && game->dfs_stack->data)
	{
		free(game->dfs_stack->data);
		game->dfs_stack->data = NULL;
	}
	exit (0);
}
