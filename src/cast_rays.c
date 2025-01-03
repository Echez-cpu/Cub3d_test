/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 16:28:45 by pokpalae          #+#    #+#             */
/*   Updated: 2025/01/01 17:54:40 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	generate_rays(t_field_of_view *camera, t_game_data *data)
{
	t_cast_ray	view_ray;
	int			i;

	i = 0;
	view_ray = data->casted_ray;
	while (i < data->win_width)
	{
		fill_raycastg_para(i, &view_ray, camera);
		initialize_ray_traversal(&view_ray, camera);
		step_through_grid(data, &view_ray);
		compute_wall_visualization(&view_ray, data, camera);
		map_texture_to_ray_hit(data, &data->texinfo, &view_ray, i);
		i++;
	}
	return (0);
}

void	map_texture_to_ray_hit(t_game_data *data, t_texinfo *txture,
		t_cast_ray *ray, int x)
{
	int	y;
	int	color;

	set_texture_direction(data, ray);
	txture->x = (int)(ray->wall_x * txture->size);
	if ((ray->side == 0 && ray->dir_x < 0) || (ray->side == 1
			&& ray->dir_y > 0))
		txture->x = txture->size - txture->x - 1;
	txture->step = 1.0 * txture->size / ray->line_height;
	txture->pos = (ray->draw_start - data->win_height / 2 + ray->line_height
			/ 2) * txture->step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		txture->y = (int)txture->pos & (txture->size - 1);
		txture->pos += txture->step;
		color = data->textures[txture->index][txture->size * txture->y
			+ txture->x];
		if (txture->index == NORTH || txture->index == EAST)
			color = (color >> 1) & 0x7F7F7F;
		if (color > 0)
			data->texture_pixels[y][x] = color;
		y++;
	}
}

void	set_texture_direction(t_game_data *data, t_cast_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			data->texinfo.index = WEST;
		else
			data->texinfo.index = EAST;
	}
	else
	{
		if (ray->dir_y > 0)
			data->texinfo.index = SOUTH;
		else
			data->texinfo.index = NORTH;
	}
}

// int y = view_ray.draw_start;
// while (y < view_ray.draw_end)
// {
// 	if (view_ray.side == 0)
// 	data->texture_pixels[y][i] = 0xFF0000; // Red for vertical walls
// 	else
// 	data->texture_pixels[y][i] = 0x00FF00; // Green for horizontal walls

// 	y++;
// }
