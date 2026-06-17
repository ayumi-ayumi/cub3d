#include "cub3d.h"
#include "exec.h"/*for put_pixel*/
#include <math.h>
#include <stdio.h>/*for debuggin*/

static int	on_pos(t_play *play, int i, int j)
{
	if (fabs((double)i / MINI - play->pos.x) < 0.1
		&& fabs((double)j / MINI - play->pos.y) < 0.1)
		return (TRUE);
	return (FALSE);
}

static t_pos	convert(t_vec a)
{
	t_pos	result;

	result.col = (int)(a.x * (double)MINI);
	result.row = (int)(a.y * (double)MINI);
	return (result);
}

static void	put_dir(t_map map, t_data *screen, t_play play)
{
	double	t;
	t_pos	pixel;
	t_pos	max;

	t = 0.0;
	max.col = map.width * MINI;
	max.row = map.height * MINI;
	while(t <= 2.0)
	{
		pixel = convert(add_vec(play.pos, mult_vec(t, play.dir)));
		printf("hello from put_dir %d, %d \n", pixel.col, pixel.row);
		if (pixel.col > max.col || pixel.row >  max.row || pixel.col < 0 || pixel.row < 0)
			break;
		put_pixel(screen, pixel.col, pixel.row, 0xFFFFFF);
		t += 0.01;
	}
}

void	draw_mini_map(t_map *map, t_play *play, t_data *screen)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <  map->width * MINI)
	{
		j = 0;
		while (j < map->height * MINI)
		{
			if (on_pos(play, i, j) == TRUE)
				put_pixel(screen, i, j, 16776960 / 3);
			else
				put_pixel(screen, i, j, 16776960 / 2);
			j++;
		}
		i++;
	}
	put_dir(*map, screen, *play);
}
