/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 03:26:02 by pokpalae          #+#    #+#             */
/*   Updated: 2024/12/27 03:26:07 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub.h"

void	configure_textures(t_game_data *data)
{
	data->textures = ft_calloc(5, sizeof * data->textures);
	if (!data->textures)
		exit_cleanly(data, is_faulty("Error: memory allocation failed\n"));
	data->textures[NORTH] = get_texture_from_xpm(data, data->texinfo.north);
	data->textures[SOUTH] = get_texture_from_xpm(data, data->texinfo.south);
	data->textures[EAST] = get_texture_from_xpm(data, data->texinfo.east);
	data->textures[WEST] = get_texture_from_xpm(data, data->texinfo.west);
}


static int	*get_texture_from_xpm(t_game_data *data, char *path)
{
	t_img	tmp;
	int		*buffer;
	int		x;
	int		y;

	init_texture_img(data, &tmp, path);
	buffer = ft_calloc(1,
			sizeof * buffer * data->texinfo.size * data->texinfo.size);
	if (!buffer)
		exit_cleanly(data, is_faulty("Error: memory allocation failed\n"));
	y = 0;
	while (y < data->texinfo.size)
	{
		x = 0;
		while (x < data->texinfo.size)
		{
			buffer[y * data->texinfo.size + x]
				= tmp.address[y * data->texinfo.size + x];
			++x;
		}
		y++;
	}
	mlx_destroy_image(data->mlx, tmp.img);
	return (buffer);
}
