#ifndef EXEC_H
# define EXEC_H
# define SCREEN_HEIGHT 640
# define SCREEN_WIDTH 480
# define IMG_WIDTH 32
# define IMG_HEIGHT 32
# define NORTH_SOUTH 1
# define WEST_EAST 0

# include "cub3d.h"

/* mlx */
int			init_mlx(t_game *game, t_exec *exec);
void		free_mlx(t_game *game, t_exec *exec);


int			init_play_data(t_game *game, t_exec *exec);
int			raycast(t_game *game, t_exec *exec);
void		calc_start_values(t_play *play, double cam_x);
#endif
