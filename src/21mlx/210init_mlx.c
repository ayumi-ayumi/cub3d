#include "cub3d.h"
#include "exec.h"
#include <mlx.h>
#include <stddef.h>/*for NULL*/
#include <stdio.h>

/*initiate whatever possible to 0 or NULL*/
static void	nulling_init(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->exec.no = NULL;
	game->exec.so = NULL;
	game->exec.we = NULL;
	game->exec.ea = NULL;
}

/*if mlx fails NULL will be returned ... guard is in calling function*/
static void	*load_texture(t_game *game, char *path)
{
	void	*texture;
	int		width;
	int		height;

	width = TEXTURE_WIDTH;
	height = TEXTURE_HEIGHT;
	texture = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	return (texture);
}

/*loading paths to mlx pictures*/
static int	init_mlx_texture(t_game *game)
{
	game->exec.no = load_texture(game, game->config.no);
	if (!(game->exec.no))
		return (FAIL);
	game->exec.so = load_texture(game, game->config.so);
	if (!(game->exec.so))
		return (free_mlx_texture(game->mlx, (void **)&game->exec.no), FAIL);
	game->exec.we = load_texture(game, game->config.we);
	if (!(game->exec.we))
		return (free_mlx_texture(game->mlx, (void **)&game->exec.no),
			free_mlx_texture(game->mlx, (void **)&game->exec.so), FAIL);
	game->exec.ea = load_texture(game, game->config.ea);
	if (!(game->exec.ea))
		return (free_mlx_texture(game->mlx, (void **)&game->exec.no),
			free_mlx_texture(game->mlx, (void **)&game->exec.so),
			free_mlx_texture(game->mlx, (void **)&game->exec.ea), FAIL);
	return (SUCCESS);
}

int	init_mlx(t_game *game)
{
	nulling_init(game);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (FAIL);
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	if (!(game->win))
		return (free_mlx(game), FAIL);
	if (init_mlx_texture(game) == FAIL)
		return (free_mlx(game), free_win(game), FAIL);
	return (SUCCESS);
}
