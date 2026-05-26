#ifndef EXEC_H
# define EXEC_H
# define SCREEN_HEIGHT 640
# define SCREEN_WIDTH 480
# include "parser.h" /*for t_game*/


typedef struct s_img
{
	void	*no;
	void	*so;
	void	*we;
	void	*ea;
	int		width;
	int		height;
}			t_img;

typedef struct s_exec
{
	void	*mlx;
	void	*win;
	t_img	img;
}	t_exec;

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
