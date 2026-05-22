#include "cub3d.h"
#include "exec.h"
#include "parser.h"
#include <mlx.h>
#include <stddef.h>/*for NULL*/

/*initiate whatever possible to 0 or NULL*/
static void	nulling_init(t_exec *exec)
{
	exec->mlx = NULL;
	exec->win = NULL;
	exec->img.no = NULL;
	exec->img.so = NULL;
	exec->img.we = NULL;
	exec->img.ea = NULL;
	exec->img.width = 32;/*probably needs to be bigger*/
	exec->img.height = 32;
}

/*if mlx fails NULL will be returned ... guard is in calling function*/
static void	*load_texture(t_exec *exec, char *path)
{
	t_img	*img;
	void	*texture;

	img = &exec->img;
	texture = mlx_xpm_file_to_image(exec->mlx, path, &img->width, &img->height);
	return (texture);
}

/*loading paths to mlx pictures*/
static int	init_mlx_img(t_game *game, t_exec *exec)
{
	exec->img.no = load_texture(exec, game->config->no);
	if (!(exec->img.no))
		return (FAIL);
	exec->img.so = load_texture(exec, game->config->so);
	if (!(exec->img.so))
		return (FAIL);
	exec->img.we = load_texture(exec, game->config->we);
	if (!(exec->img.we))
		return (FAIL);
	exec->img.ea = load_texture(exec, game->config->ea);
	if (!(exec->img.ea))
		return (FAIL);
	return (SUCCESS);
}

int	init_mlx(t_game *game, t_exec *exec)
{
	nulling_init(exec);
	exec->mlx = mlx_init();
	if (!exec->mlx)
		return(FAIL);
	exec->win = mlx_new_window(exec->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	if (!(exec->win))
		return (FAIL);
	if (init_mlx_img(game, exec) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
