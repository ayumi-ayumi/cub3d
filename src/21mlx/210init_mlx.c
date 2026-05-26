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
	exec->texture.no = NULL;
	exec->texture.so = NULL;
	exec->texture.we = NULL;
	exec->texture.ea = NULL;
	exec->texture.width = 32;/*probably needs to be bigger*/
	exec->texture.height = 32;
}

/*if mlx fails NULL will be returned ... guard is in calling function*/
static void	*load_texture(t_exec *exec, char *path)
{
	t_texture	*img;
	void	*texture;

	texture = &exec->img;
	texture = mlx_xpm_file_to_image(exec->mlx, path, &texture->width, &img->height);
	return (texture);
}

/*loading paths to mlx pictures*/
static int	init_mlx_texture(t_game *game, t_exec *exec)
{
	exec->texture.no = load_texture(exec, game->config->no);
	if (!(exec->texture.no))
		return (FAIL);
	exec->texture.so = load_texture(exec, game->config->so);
	if (!(exec->texture.so))
		return (FAIL);
	exec->texture.we = load_texture(exec, game->config->we);
	if (!(exec->texture.we))
		return (FAIL);
	exec->texture.ea = load_texture(exec, game->config->ea);
	if (!(exec->texture.ea))
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
