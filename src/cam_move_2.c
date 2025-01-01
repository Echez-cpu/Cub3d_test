/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_move_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 16:38:55 by pokpalae          #+#    #+#             */
/*   Updated: 2025/01/01 17:15:28 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	apply_turn(t_game_data *data, double turn_rate)
{
	t_field_of_view	*cam;
	double			tmp_i;

	cam = &data->first_person;
	tmp_i = cam->dir_x;
	cam->dir_x = cam->dir_x * cos(turn_rate) - cam->dir_y * sin(turn_rate);
	cam->dir_y = tmp_i * sin(turn_rate) + cam->dir_y * cos(turn_rate);
	tmp_i = cam->plane_x;
	cam->plane_x = cam->plane_x * cos(turn_rate) - cam->plane_y
		* sin(turn_rate);
	cam->plane_y = tmp_i * sin(turn_rate) + cam->plane_y * cos(turn_rate);
	return (1);
}

int	rotate_camera(t_game_data *data, double rotdir)
{
	int		shifted;
	double	turn_rate;

	shifted = 0;
	turn_rate = TURN_RATE * rotdir;
	shifted += apply_turn(data, turn_rate);
	return (shifted);
}
