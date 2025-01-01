/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 03:26:02 by pokpalae          #+#    #+#             */
/*   Updated: 2025/01/01 17:55:35 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	config_texture_img(t_game_data *data, t_img *image, char *path)
{
	init_empty_image(image);
	image->img = mlx_xpm_file_to_image(data->mlx, path, &data->texinfo.size,
			&data->texinfo.size);
	if (image->img == NULL)
		exit_cleanly(data, is_faulty("Error: image creation failed\n"));
	image->address = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return ;
}

int	*get_texture_from_xpm(t_game_data *data, char *path)
{
	t_img	tmp;
	int		*buffer;
	int		x;
	int		y;

	config_texture_img(data, &tmp, path);
	buffer = ft_calloc(1, sizeof(*buffer) * data->texinfo.size
			* data->texinfo.size);
	if (!buffer)
		exit_cleanly(data, is_faulty("Error: memory allocation failed\n"));
	y = 0;
	while (y < data->texinfo.size)
	{
		x = 0;
		while (x < data->texinfo.size)
		{
			buffer[y * data->texinfo.size + x] = tmp.address[y
				* data->texinfo.size + x];
			++x;
		}
		y++;
	}
	mlx_destroy_image(data->mlx, tmp.img);
	return (buffer);
}

void	configure_textures(t_game_data *data)
{
	data->textures = ft_calloc(5, sizeof(*data->textures));
	if (!data->textures)
		exit_cleanly(data, is_faulty("Error: memory allocation failed\n"));
	data->textures[NORTH] = get_texture_from_xpm(data, data->texinfo.north);
	data->textures[SOUTH] = get_texture_from_xpm(data, data->texinfo.south);
	data->textures[EAST] = get_texture_from_xpm(data, data->texinfo.east);
	data->textures[WEST] = get_texture_from_xpm(data, data->texinfo.west);
}
