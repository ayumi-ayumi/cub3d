#include "mlx.h"
#include "exec.h"
#include "cub3d.h"
#include "libft.h"
#include <stddef.h>
#include <stdio.h>/*for debugging */

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

	printf("DEBUG 37\n");
	if (!game->mlx)//removed check for game->exec because exec is not nulled when initialized
		return ;
	i = 0;
	while (i < 4)
	{
		printf("DEBUG i = %d\n", i);
		free_mlx_texture(game->mlx, (void **)&game->exec.dir_texture[i].img);
		ft_free((void **)&game->exec.dir_texture[i]);
		i++;
	}
	if (game->exec.scre.img)
		mlx_destroy_image(game->mlx, game->exec.scre.img);
	// ft_free((void **)&game->config.dir_path);
	// free_string_array(game->config.dir_path);
	free_win(game);
	free_mlx(game);
}
