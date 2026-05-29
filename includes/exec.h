#ifndef EXEC_H
# define EXEC_H
# define SCREEN_HEIGHT 640
# define SCREEN_WIDTH 480
# define TEXTURE_WIDTH 32
# define TEXTURE_HEIGHT 32

# include "cub3d.h"

/*mlx img for walls*/
// typedef struct s_exec
// {
// 	void	*no;
//  	void	*so;
//  	void	*we;
//  	void	*ea;
// }			t_exec;

typedef	struct s_vec
{
	double	x;
	double	y;
}	t_vec;

typedef struct s_raycast
{
	t_vec	pos;
	t_vec	dir;
	t_vec	plane;
	double	time;
	double	old_time;
}	t_raycast;

/* mlx */
int			init_mlx(t_game *game);
void		free_mlx(t_game *game);
void		free_win(t_game *game);
void		free_mlx_texture(void *mlx, void **target);
// void		free_entire_mlx(t_game *game, t_exec *exec);


#endif
