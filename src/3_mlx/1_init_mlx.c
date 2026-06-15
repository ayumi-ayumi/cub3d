#include "cub3d.h"
#include "exec.h"
#include "libft.h"
#include <mlx.h>
#include <stddef.h>/*for NULL*/

/*initiate whatever possible to 0 or NULL*/
static void	nulling_init(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	// while (i < 5)
	// {
	// 	game->exec.dir_texture[i].img = NULL;
	// 	i++;
	// }
	ft_bzero(&game->exec.scre, sizeof(t_data));
	game->exec.scre.img = NULL;
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
	if (!texture)
		return (NULL);
	return (texture);
}

/*loading paths to mlx pictures, creating scre img*/
static int	init_mlx_texture(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->exec.dir_texture = ft_calloc(5, sizeof(t_data));
	if (!game->exec.dir_texture)
		return (FAIL);
	while (i < 4)
	{
		game->exec.dir_texture[i].img = load_texture(game, game->config.dir_path[i]);
		// ft_free((void **)&game->config.dir_path[i]);
		if (!(game->exec.dir_texture[i].img))
		{
			j = i;
			while (j > 0)
			{
				free_mlx_texture(game->mlx, (void **)&game->exec.dir_texture[j].img);
				ft_free((void **)&game->exec.dir_texture[j].img);
				j--;
			}
			return (FAIL);
		}
		game->exec.dir_texture[i].addr = mlx_get_data_addr(game->exec.dir_texture[i].img,
				&game->exec.dir_texture[i].bpp, &game->exec.dir_texture[i].line_length,
				&game->exec.dir_texture[i].endian);

		i++;
	}
	return (SUCCESS);
}


// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;
//
// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned	int*)dst = color;
// }
// #define GREEN_PIXEL 0xFF00
// #define RED_PIXEL 0xFF0000

// typedef struct s_rect
// {
//     int	x;
//     int	y;
//     int width;
//     int height;
//     int color;
// }	t_rect;
//
// /* The x and y coordinates of the rect corresponds to its upper left corner. */
//
// int	render_rect(t_game *game, t_rect rect)
// {
// 	int	i;
// 	int	j;
//
// 	if (game->win == NULL)
// 		return (1);
// 	i = rect.y;
// 	while (i < rect.y + rect.height)
// 	{
// 		j = rect.x;
// 		while (j < rect.x + rect.width)
// 			mlx_pixel_put(game->mlx, game->win, j++, i, rect.color);
// 		++i;
// 	}
// 	return (0);
// }

static int	init_scre_buffer(t_game *game, t_data *scre)
{
	scre->img = NULL;
	scre->img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!scre->img)
		return (free_win(game), free_mlx(game), FAIL);
	scre->addr = mlx_get_data_addr(scre->img,
			&scre->bpp, &scre->line_length, &scre->endian);
	return (SUCCESS);
}

/*initialize mlx, load textures and create buffer scre img*/
int	init_mlx(t_game *game)
{
	nulling_init(game);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (FAIL);
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	if (!game->win)
		return (free_mlx(game), FAIL);
	// render_rect(game, (t_rect){0, 0, SCREEN_WIDTH, SCREEN_HEIGHT / 2, RED_PIXEL});
	// render_rect(game, (t_rect){0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2, GREEN_PIXEL});
	if (init_mlx_texture(game) == FAIL)
		return (free_win(game), free_mlx(game), FAIL);
	if (init_scre_buffer(game, &game->exec.scre) == FAIL)
		return (free_entire_mlx(game), FAIL);
	return (SUCCESS);
}
