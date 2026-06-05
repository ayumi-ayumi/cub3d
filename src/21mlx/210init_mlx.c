#include "cub3d.h"
#include "exec.h"
#include "libft.h"
#include <mlx.h>
#include <stddef.h>/*for NULL*/

/*initiate whatever possible to 0 or NULL*/
static void	nulling_init(t_game *game, t_exec *exec)
{
	game->mlx = NULL;
	game->win = NULL;
	exec->no = NULL;
	exec->so = NULL;
	exec->we = NULL;
	exec->ea = NULL;
	ft_bzero(&exec->screen, sizeof(t_data));
}

/*if mlx fails NULL will be returned ... guard is in calling function*/
static void	*load_texture(t_game *game, char *path)
{
	void	*texture;
	int		width;
	int		height;

	width = IMG_WIDTH;
	height = IMG_HEIGHT;
	texture = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	return (texture);
}

/*loading paths to mlx pictures, creating screen img*/
static int	init_mlx_img(t_game *game, t_exec *exec)
{
	exec->no = load_texture(game, game->config.no);
	if (!(exec->no))
		return (FAIL);
	exec->so = load_texture(game, game->config.so);
	if (!(exec->so))
		return (FAIL);
	exec->we = load_texture(game, game->config.we);
	if (!(exec->we))
		return (FAIL);
	exec->ea = load_texture(game, game->config.ea);
	if (!(exec->ea))
		return (FAIL);
	exec->screen.img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!exec->screen.img)
		return (FAIL);
	return (SUCCESS);
}

int	init_mlx(t_game *game, t_exec *exec)
{
	nulling_init(game, exec);
	game->mlx = mlx_init();
	if (!game->mlx)
		return(FAIL);
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	if (!(game->win))
		return (FAIL);
	if (init_mlx_img(game, exec) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
