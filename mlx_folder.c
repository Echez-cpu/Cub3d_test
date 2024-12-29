/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_folder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 03:26:17 by pokpalae          #+#    #+#             */
/*   Updated: 2024/12/27 03:26:21 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub.h"

void	setup_image(t_game_data *data, t_img *image, int width, int height)
{
	reset_img_struct(image);
	image->img = mlx_new_image(data->mlx, width, height);
	if (image->img == NULL)
		exit_cleanly(data, is_faulty("Error: mlx image not created\n"));
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


void	initialize_mlx(t_game_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit_cleanly(data, is_faulty("Error: mlx init failed\n"));
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!data->win)
		exit_cleanly(data, is_faulty("Error: mlx window creation failed\n"));
	
	return ;
}