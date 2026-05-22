//#include "cub3d.h"
#include "parser.h"
#include <unistd.h>
#include <stdlib.h>
#include <mlx.h>

void	free_map(t_map *map)
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

void	cleanup_and_exit(t_game *game)
{
	if (!game)
		return ;
//	free_mlx(game);//mlx gets initialized and freed in execution
	if (game->map)
	{
		free_map(game->map);
		// if (game->file_path)
		// 	free(game->file_path);
		game->map = NULL;
	}
	if (game->copy)
	{
		free_map(game->copy);
		// if (game->file_path)
		// 	free(game->file_path);
		game->copy = NULL;
	}
	// if (game->dfs_stack && game->dfs_stack->data)
	// {
	// 	free(game->dfs_stack->data);
	// 	game->dfs_stack->data = NULL;
	// }
	exit (0);
}
