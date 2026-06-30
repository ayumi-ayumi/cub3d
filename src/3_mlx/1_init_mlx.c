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
	game->exec.wall_texture = NULL;
	ft_bzero(&game->exec.scre, sizeof(t_data));
	game->exec.scre.img = NULL;
	ft_bzero(&game->minimap, sizeof(t_data));
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
static int	init_mlx_texture(t_game *game, t_data *wall_texture)
{
	int	i;
	int	j;

	i = 0;
	wall_texture = ft_calloc(5, sizeof(t_data));
	if (!wall_texture)
		return (FAIL);
	while (i < 4)
	{
		wall_texture[i].img = load_texture(game, game->config.texture_paths[i]);
		if (!(wall_texture[i].img))
		{
			j = i;
			while (j >= 0)
				free_mlx_texture(game->mlx, (void **)&wall_texture[j--].img);
			ft_free((void **)&wall_texture);
			return (print_error("Texture path is invalid"), FAIL);
		}
		wall_texture[i].addr = mlx_get_data_addr(wall_texture[i].img,
				&wall_texture[i].bpp, &wall_texture[i].line_length,
				&wall_texture[i].endian);
		i++;
	}
	game->exec.wall_texture = wall_texture;
	return (SUCCESS);
}

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
	if (init_mlx_texture(game, game->exec.wall_texture) == FAIL)
		return (free_win(game), free_mlx(game), FAIL);
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	if (!game->win)
		return (free_mlx(game), FAIL);
	if (init_scre_buffer(game, &game->exec.scre) == FAIL)
		return (free_entire_mlx(game), FAIL);
	return (SUCCESS);
}
