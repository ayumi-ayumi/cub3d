#ifndef EXEC_H
# define EXEC_H
# define SCREEN_HEIGHT 640
# define SCREEN_WIDTH 480
# define IMG_WIDTH 32
# define IMG_HEIGHT 32

# include "cub3d.h"

/*mlx img for walls*/
typedef struct s_mlx
{
	void	*no;
 	void	*so;
 	void	*we;
 	void	*ea;
}			t_mlx;

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
int			init_mlx(t_game *game, t_exec *exec);
void		free_mlx(t_exec *exec);


#endif
