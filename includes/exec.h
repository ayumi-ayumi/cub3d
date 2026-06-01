#ifndef EXEC_H
# define EXEC_H
# define SCREEN_HEIGHT 640
# define SCREEN_WIDTH 480
# define IMG_WIDTH 32
# define IMG_HEIGHT 32

# include "cub3d.h"

typedef	struct s_vec
{
	double	x;
	double	y;
}	t_vec;

typedef	struct s_idx
{
	char	i;
	char	j;
}			t_idx;

typedef struct s_play
{
	t_vec	pos;
	t_vec	dir;
	t_vec	plane;
	t_vec	ray;
	t_idx	map;
	t_vec	delta_dist;
	t_vec	side_dist;//maybe not needed
	t_idx	step;//what dir to step
	int		hit;//maybe not needed
	int		side;//which wall side jmaybe not needed
	double	perp_wall_dist;
	double	time;
	double	old_time;
}	t_play;

/*mlx img for walls*/
typedef struct s_exec
{
	void	*no;
 	void	*so;
 	void	*we;
 	void	*ea;
	t_play	play;
}			t_exec;


/* mlx */
int			init_mlx(t_game *game, t_exec *exec);
void		free_mlx(t_game *game, t_exec *exec);


int			init_play_data(t_game *game, t_exec *exec);
int			raycast(t_game *game, t_exec *exec);
#endif
