#include "cub3d.h"

void	put_pixel(t_data *img, int x, int y, int colour)
{
	int	pixel;

	pixel = y * (img->line_length / 4) + x;
	img->addr[pixel] = colour;
}
