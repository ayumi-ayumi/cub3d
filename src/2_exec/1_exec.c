#include "cub3d.h"
#include "exec.h"
#include "libft.h"/*for ft_bzero*/
#include <mlx.h>


static int	done(void)/*TODO*/
{
	return (TRUE);
}

/*converts grid to coords (values stored in cols)*/
static int	convert_grid_to_coords(t_map map)
{
	int	x_i;
	int	y_j;
	int	max_col;
	int	max_row;
	char **temp;
	
	max_row = map.height - 1;
	max_col = map.width - 1;
	temp = map.grid;
	x_i = 0;
	y_j = 0;
	while (x_i <= max_col)
	{
		map.grid[x_i] = (char *)ft_calloc(map.height, sizeof(char));
		if (!map.grid)
			return(ft_free_arr(&temp), ft_free_arr(&map.grid), FAIL);
		y_j = 0;
		while (y_j <= max_row)
		{
			temp[x_i][y_j] = map.grid[max_row - y_j][x_i] - '0';
			y_j++;
		}
		x_i++;
	}
	return (ft_free_arr(&temp), SUCCESS);
}


/*setup of screen and start game loop*/
int	execution(t_game *game)
{
	t_exec	exec;
	
	if (init_mlx(game, &exec) == FAIL || game->mlx == NULL
		|| init_play_data(game, &exec) == FAIL
		|| convert_grid_to_coords(game->map))
		return (cleanup_exec(game, &exec), FAIL);
	while (!done())
	{
		raycast(game, &exec);
	}
	return (cleanup_exec(game, &exec), SUCCESS);
}


// Testcode for execute
// #define mapWidth 24
// #define mapHeight 24
// #define screenWidth 640
// #define screenHeight 480
//  int	main(void)
//  {
// 	int worldMap[mapWidth][mapHeight]=
// 	{
// 	  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
// 	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	  {1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
// 	  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
// 	  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	  {1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
// 	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	  {1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	  {1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	  {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
// 	};
//  }


