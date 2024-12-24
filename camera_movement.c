

#include "cub.h"



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



 int	propel_forward(t_game_data *data)
{
	double	i;
	double	j;

	i = data->first_person.pos_x + data->first_person.dir_x * MOVESPEED;
	j = data->first_person.pos_y + data->first_person.dir_y * MOVESPEED;
	return (move_if_valid(data, i, j));
}



 int	propel_backward(t_game_data *data)
{
	double	i;
	double	j;

	i = data->first_person.pos_x - data->first_person.dir_x * MOVESPEED;
	j = data->first_person.pos_y - data->first_person.dir_y * MOVESPEED;
	return (move_if_valid(data, i, j));
}


 int	glide_left(t_game_data *data)
{
	double	i;
	double	j;

	i = data->first_person.pos_x + data->first_person.dir_y * MOVESPEED;
	j = data->first_person.pos_y - data->first_person.dir_x * MOVESPEED;
	return (move_if_valid(data, i, j));
}



 int	glide_right(t_game_data *data)
{
	double	i;
	double	j;

	i = data->first_person.pos_x - data->first_person.dir_y * MOVESPEED;
	j = data->first_person.pos_y + data->first_person.dir_x * MOVESPEED;
	return (move_if_valid(data, i, j));
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


 int	apply_turn(t_game_data *data, double turn_rate)
{
	t_field_of_view		*cam;
	double		tmp_i;

	cam = &data->first_person;
	tmp_i = cam->dir_x;
	cam->dir_x = cam->dir_x * cos(turn_rate) - cam->dir_y * sin(turn_rate);
	cam->dir_y = tmp_i * sin(turn_rate) + cam->dir_y * cos(turn_rate);
	tmp_i = cam->plane_x;
	cam->plane_x = cam->plane_x * cos(turn_rate) - cam->plane_y * sin(turn_rate);
	cam->plane_y = tmp_i * sin(turn_rate) + cam->plane_y * cos(turn_rate);
	return (1);
}

