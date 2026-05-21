#include "cub3d.h"
#include "exec.h"
#include "parser.h"/*for t_game*/
#include <mlx.h>

static void	cleanup_exec(t_game *game)
{
	if (game->mlx)
		mlx_destroy_display(game->mlx);
}


static void	free_mlx_img(t_game *game, void **target)
{
	if (!game || !game->mlx || !target || !*target)
		return ;
	mlx_destroy_image(game->mlx, *target);
	*target = NULL;
}

static void	free_mlx(t_game *game)
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


int	execution(t_game *game)
{
	if (init_window(game) == FAIL)
		return (cleanup_exec(game), FAIL);
}
