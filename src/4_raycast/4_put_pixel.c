#include "cub3d.h"
#include <limits.h>
#include <inttypes.h>

/*iterates over img_addr byte by byte char is one byt*/
void	put_pixel(t_data *img, int x, int y, unsigned int color)
{
	char 	*pixel;
	int	i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_length + x * (img->bpp / 8));
	while (i > 0)
	{
		if (img->endian != 0)
			*(pixel++) = (color >> i) & 0xFF;
		else
			*(pixel++) = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}

}

/*
 * TODO enhance performance by precalculating img->bpp /8 and put it in a struct
 * last points to the last 8 bits of the current pixel
 * last and first are of type char so that they always iterate bits (1 byte) at a time
 */

/*iterates over pixelcolor byte by byte and copies last 4 bytes in color*/
unsigned int	get_pixel_colour(t_data *img, int x, int y)
{
	char			*first;
	char			*last;
	unsigned int	color;
	int				bytespp;

	color = 0;
	bytespp = img->bpp / CHAR_BIT;
	first = img->addr + (y * img->line_length + x * bytespp);
 	last = first + bytespp - 1;
	if (img->bpp > (int)sizeof(unsigned int) * CHAR_BIT)
		return (0);
	while (img->endian != 0 && first <= last)
	{
		color = color << CHAR_BIT;
		color += ((unsigned int)(*first)) & 0xFF;
		first++;
	}
	while (img->endian == 0 && first <= last)
	{
		color = color << CHAR_BIT;
		color += ((unsigned int)(*last)) & 0xFF;
		last--;
	}
	return (color);
}
