
#include "../cub.h"


static int	rgb_bounds_checker(int *rgb)
{
	int	x;

	x = 0;
	while (x < 3)
	{
		if (rgb[x] < 0 || rgb[x] > 255)
			return(is_faulty("Error: invalid RGB colour\n"));
		x++;
	}
	return (0);
}


static unsigned long	encode_rgb_as_int(int *rgb_array)
{
	unsigned long	result;
	int				r;
	int				g;
	int				b;

	r = rgb_array[0];
	g = rgb_array[1];
	b = rgb_array[2];
	result = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
	return (result);
}


int	validate_game_assets(t_texinfo *text)
{
	if (!text->north || !text->south || !text->west
		|| !text->east)
		return(is_faulty("Error: texture is missing\n"));
	if (!text->floor || !text->ceiling)
		return(is_faulty("Error: colour (ceiling and floor) is missing\n"));
	if (set_fd(text->north, false) == 1
		|| set_fd(text->south, false) == 1
		|| set_fd(text->west, false) == 1
		|| set_fd(text->east, false) == 1
		|| rgb_bounds_checker(text->floor) == 1
		|| rgb_bounds_checker(text->ceiling) == 1)
		return (FAIL);
	 text->hex_floor = encode_rgb_as_int(text->floor);
	 text->hex_ceiling = encode_rgb_as_int(text->ceiling);
	return (0);
}
