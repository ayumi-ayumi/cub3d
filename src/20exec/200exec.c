// #include "cub3d.h"
#include "exec.h"
#include <mlx.h>
#include <stdio.h>
// static void	cleanup_exec(t_game *game)
// {
// 	if (game->mlx)
// 		free_entire_mlx(game);
// }

void	handle_key_event(t_game *game, int keycode)
{
	// if (keycode == ARROW_UP || keycode == KEY_W)
	// 	move_player(game, -1, 0, DIR_UP);
	// if (keycode == ARROW_RIGHT || keycode == KEY_D)
	// 	move_player(game, 0, 1, DIR_RIGHT);
	// if (keycode == ARROW_DOWN || keycode == KEY_S)
	// 	move_player(game, 1, 0, DIR_DOWN);
	// if (keycode == ARROW_LEFT || keycode == KEY_A)
	// 	move_player(game, 0, -1, DIR_LEFT);
	if (keycode == KEY_ESC)
		cleanup_and_exit(game);
}

int	key_hook(int keycode, void *param)
{
	t_game		*game;

	game = (t_game *)param;
	handle_key_event(game, keycode);
	return (0);
}



int	close_window(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	cleanup_and_exit(game);
	return (1);
}

int	start_graphics(t_game *game)
{
	if (!game || !game->mlx || !game->win)
		return (0);
	if (!game->exec.no || !game->exec.so || !game->exec.so || !game->exec.ea)
		return (0);
	// render_map(game);
	mlx_hook(game->win, 2, 1L << 0, key_hook, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop(game->mlx);
	return (1);
}

int	execution(t_game *game)
{
	// t_exec	exec;
	if (init_mlx(game) == FAIL || !game->mlx)
		return (FAIL);
	start_graphics(game);
	// cleanup_exec(game, &exec);
	return (SUCCESS);
}
