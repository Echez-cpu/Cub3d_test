/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 03:28:24 by pokpalae          #+#    #+#             */
/*   Updated: 2025/01/01 17:54:34 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	propel_forward(t_game_data *data)
{
	double	i;
	double	j;

	i = data->first_person.pos_x + data->first_person.dir_x * WALKING_SPEED;
	j = data->first_person.pos_y + data->first_person.dir_y * WALKING_SPEED;
	return (move_if_valid(data, i, j));
}

int	propel_backward(t_game_data *data)
{
	double	i;
	double	j;

	i = data->first_person.pos_x - data->first_person.dir_x * WALKING_SPEED;
	j = data->first_person.pos_y - data->first_person.dir_y * WALKING_SPEED;
	return (move_if_valid(data, i, j));
}

int	glide_left(t_game_data *data)
{
	double	i;
	double	j;

	i = data->first_person.pos_x + data->first_person.dir_y * WALKING_SPEED;
	j = data->first_person.pos_y - data->first_person.dir_x * WALKING_SPEED;
	return (move_if_valid(data, i, j));
}

int	glide_right(t_game_data *data)
{
	double	i;
	double	j;

	i = data->first_person.pos_x - data->first_person.dir_y * WALKING_SPEED;
	j = data->first_person.pos_y + data->first_person.dir_x * WALKING_SPEED;
	return (move_if_valid(data, i, j));
}

int	camera_spin(t_game_data *data)
{
	int	moved;

	moved = 0;
	if (data->first_person.move_y == 5)
		moved += propel_forward(data);
	if (data->first_person.move_y == -5)
		moved += propel_backward(data);
	if (data->first_person.move_x == -5)
		moved += glide_left(data);
	if (data->first_person.move_x == 5)
		moved += glide_right(data);
	if (data->first_person.rotate != 0)
		moved += rotate_camera(data, data->first_person.rotate);
	return (moved);
}
