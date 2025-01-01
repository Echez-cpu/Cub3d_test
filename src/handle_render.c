/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 21:31:23 by pokpalae          #+#    #+#             */
/*   Updated: 2025/01/01 17:15:45 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	update_graphics(t_game_data *data)
{
	data->first_person.moved += camera_spin(data);
	if (data->first_person.moved == 0)
		return (0);
	draw_graphics(data);
	return (0);
}

void	draw_graphics(t_game_data *data)
{
	allocate_pixel_memory(data);
	zero_out_ray(&data->casted_ray);
	generate_rays(&data->first_person, data);
	paint_frame(data);
}

void	allocate_pixel_memory(t_game_data *data)
{
	int	i;

	if (data->texture_pixels)
		free_things((void **)data->texture_pixels);
	data->texture_pixels = ft_calloc(data->win_height + 1,
			sizeof(*data->texture_pixels));
	if (!data->texture_pixels)
		exit_cleanly(data, is_faulty("Error: memory allocation failed\n"));
	i = 0;
	while (i < data->win_height)
	{
		data->texture_pixels[i] = ft_calloc(data->win_width + 1,
				sizeof(*data->texture_pixels));
		if (!data->texture_pixels[i])
		{
			exit_cleanly(data, is_faulty("Error: memory allocation failed\n"));
		}
		i++;
	}
}

void	paint_frame(t_game_data *data)
{
	t_img	image;
	int		x;
	int		y;

	image.img = NULL;
	setup_image(data, &image, data->win_width, data->win_height);
	y = 0;
	while (y < data->win_height)
	{
		x = 0;
		while (x < data->win_width)
		{
			set_pixel_color(data, &image, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, image.img, 0, 0);
	mlx_destroy_image(data->mlx, image.img);
}
