#include "mlx.h"
#include "exec.h"
//#include "cub3d.h"
#include <stddef.h>

static void	free_mlx_img(t_exec *exec, void **target)
{
	if (!exec || !exec->mlx || !target || !*target)
		return ;
	mlx_destroy_image(exec->mlx, *target);
	*target = NULL;
	return ;
}

void	free_mlx(t_exec *exec)
{
	if (!exec || !exec->mlx)
		return ;
	free_mlx_img(exec, (void **)&exec->img.no);
	free_mlx_img(exec, (void **)&exec->img.so);
	free_mlx_img(exec, (void **)&exec->img.we);
	free_mlx_img(exec, (void **)&exec->img.ea);
	if (exec->win)
	{
		mlx_destroy_window(exec->mlx, exec->win);
		exec->win = NULL;
	}
	mlx_destroy_display(exec->mlx);
	exec->mlx = NULL;
	return ;
}

