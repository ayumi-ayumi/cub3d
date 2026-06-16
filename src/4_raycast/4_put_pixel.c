#include "cub3d.h"

void	put_pixel(t_data *img, int x, int y, unsigned int color)
{
	int	pixel;

	pixel = y * (img->line_length / 4) + x;
	((unsigned int *)img->addr)[pixel] = color;
}
