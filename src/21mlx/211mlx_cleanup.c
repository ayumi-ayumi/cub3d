#include "mlx.h"
#include "exec.h"
#include "cub3d.h"
#include <stddef.h>

void	free_mlx_texture(void *mlx, void **target)
{
	if (mlx || !target || !*target)
		return ;
	mlx_destroy_image(mlx, *target);
	*target = NULL;
	return ;
}

void	free_mlx(t_game *game)
{
	if (!game->mlx)
		return ;
	mlx_destroy_display(game->mlx);
	game->mlx = NULL;
	return ;
}

void	free_win(t_game *game)
{
	if (!game->win)
		return ;
	mlx_destroy_window(game->mlx, game->win);
	game->win = NULL;
}

void	free_entire_mlx(t_game *game)
{
	if (!&(game->exec) || !game->mlx)
		return ;
	free_mlx_texture(game->mlx, (void **)&game->exec.no);
	free_mlx_texture(game->mlx, (void **)&game->exec.so);
	free_mlx_texture(game->mlx, (void **)&game->exec.we);
	free_mlx_texture(game->mlx, (void **)&game->exec.ea);
	free_win(game);
	free_mlx(game);
}
// void	free_entire_mlx(t_game *game, t_exec *exec)
// {
// 	if (!exec || !game->mlx)
// 		return ;
// 	free_mlx_texture(game->mlx, (void **)&exec->no);
// 	free_mlx_texture(game->mlx, (void **)&exec->so);
// 	free_mlx_texture(game->mlx, (void **)&exec->we);
// 	free_mlx_texture(game->mlx, (void **)&exec->ea);
// 	if (game->win)
// 	{
// 		mlx_destroy_window(game->mlx, game->win);
// 		game->win = NULL;
// 	}
// 	mlx_destroy_display(game->mlx);
// 	game->mlx = NULL;
// 	return ;
// }
