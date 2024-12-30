/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 03:27:06 by pokpalae          #+#    #+#             */
/*   Updated: 2024/12/30 16:46:39 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	init_camera(t_field_of_view *cam)
{
	cam->dir = '\0';
	cam->pos_x = 0.0;
	cam->pos_y = 0.0;
	cam->dir_x = 0.0;
	cam->dir_y = 0.0;
	cam->plane_x = 0.0;
	cam->plane_y = 0.0;
	cam->moved = 0;
	cam->move_x = 0;
	cam->move_y = 0;
	cam->rotate = 0;
}



void	init_txtureinfo(t_texinfo *textures)
{
	textures->north = NULL;
	textures->south = NULL;
	textures->west = NULL;
	textures->east = NULL;
	textures->floor = 0;
	textures->ceiling = 0;
	textures->hex_floor = 0UL;
	textures->hex_ceiling = 0UL;
	textures->size = TEXTURE_SIZE;
	textures->step = 0.0;
	textures->pos = 0.0;
	textures->x = 0;
	textures->y = 0;
}


 void	init_mapinfo(t_mapinfo *mapinfo)
{
	mapinfo->fd = 0;
	mapinfo->line_count = 0;
	mapinfo->path = NULL;
	mapinfo->file = NULL;
	mapinfo->height = 0;
	mapinfo->width = 0;
	mapinfo->end_of_map_index = 0;
}


void	init_empty_image(t_img *img)
{
	img->img = NULL;
	img->address = NULL;
	img->pixel_bits = 0;
	img->size_line = 0;
	img->endian = 0;
}


void	setup_game_state(t_game_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->win_height = WIN_HEIGHT;
	data->win_width = WIN_WIDTH;
	init_camera(&data->first_person);
	init_txtureinfo(&data->texinfo);
	data->map = NULL;
	init_mapinfo(&data->mapinfo);
	init_empty_image(&data->minimap);
	data->texture_pixels = NULL;
	data->textures = NULL;
}


