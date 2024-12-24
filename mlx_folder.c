
#include "cub.h"



void	setup_image(t_game_data *data, t_img *image, int width, int height)
{
	reset_img_struct(image);
	image->img = mlx_new_image(data->mlx, width, height);
	if (image->img == NULL)
		// clean and exit
	image->address = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return ;
}


void	reset_img_struct(t_img *img)
{
	img->img = NULL;
	img->address = NULL;
	img->pixel_bits = 0;
	img->size_line = 0;
	img->endian = 0;
}


 void	set_pixel_color(t_game_data *data, t_img *image, int x, int y)
{
	if (data->texture_pixels[y][x] > 0)
		write_color_2_pixel(image, x, y, data->texture_pixels[y][x]);
	else if (y < data->win_height / 2)
		write_color_2_pixel(image, x, y, data->texinfo.hex_ceiling);
	else if (y < data->win_height -1)
		write_color_2_pixel(image, x, y, data->texinfo.hex_floor);
}


void	write_color_2_pixel(t_img *image, int x, int y, int color)
{
	int	pixel;

	pixel = y * (image->size_line / 4) + x;
	image->address[pixel] = color;
}
