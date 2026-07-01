#include "mlx.h"
#include "exec.h"
#include "cub3d.h"
#include "libft.h"

void	free_mlx_texture(void *mlx, void **target)
{
	if (!mlx || !target || !*target)
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
	ft_free((void **)&game->mlx);
}

void	free_win(t_game *game)
{
	if (!game->win)
		return ;
	mlx_destroy_window(game->mlx, game->win);
	ft_free((void **)&game->win);
}

void	free_entire_mlx(t_game *game)
{
	int	i;

	if (!game->mlx)
		return ;
	if (game->exec.wall_texture)
	{
		i = 0;
		while (i < 4)
		{
			if (game->exec.wall_texture[i].img)
			{
				free_mlx_texture(game->mlx,
					(void **)&game->exec.wall_texture[i].img);
			}
			i++;
		}
		ft_free((void **)&game->exec.wall_texture);
	}
	if (game->exec.scre.img)
		mlx_destroy_image(game->mlx, game->exec.scre.img);
	free_win(game);
	free_mlx(game);
}
