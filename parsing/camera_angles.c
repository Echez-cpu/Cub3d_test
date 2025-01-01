/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:32:48 by junhhong          #+#    #+#             */
/*   Updated: 2024/12/24 16:57:19 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

size_t	find_max_row_width(t_mapinfo *map, int i)
{
	size_t	find_max_width;

	find_max_width = ft_strlen(map->file[i]);
	while (map->file[i])
	{
		if (ft_strlen(map->file[i]) > find_max_width)
			find_max_width = ft_strlen(map->file[i]);
		i++;
	}
	return (find_max_width);
}

static void	config_north_south_view(t_field_of_view *cam)
{
	if (cam->dir == 'S')
	{
		cam->dir_x = 0;
		cam->dir_y = 1;
		cam->plane_x = -0.66;
		cam->plane_y = 0;
	}
	else if (cam->dir == 'N')
	{
		cam->dir_x = 0;
		cam->dir_y = -1;
		cam->plane_x = 0.66;
		cam->plane_y = 0;
	}
	else
		return ;
}

static void	config_east_west_view(t_field_of_view *cam)
{
	if (cam->dir == 'W')
	{
		cam->dir_x = -1;
		cam->dir_y = 0;
		cam->plane_x = 0;
		cam->plane_y = -0.66;
	}
	else if (cam->dir == 'E')
	{
		cam->dir_x = 1;
		cam->dir_y = 0;
		cam->plane_x = 0;
		cam->plane_y = 0.66;
	}
	else
		return ;
}

void	init_camera_angles(t_game_data *data)
{
	config_north_south_view(&data->first_person);
	config_east_west_view(&data->first_person);
}
