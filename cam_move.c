int	move_if_valid(t_game_data *data, double i, double j)
{
	int	moved;

	moved = 0;
	if (is_position_allowed(data, i, data->first_person.pos_y))
	{
		data->first_person.pos_x = i;
		moved = 1;
	}
	if (is_position_allowed(data, data->first_person.pos_x, j))
	{
		data->first_person.pos_y = j;
		moved = 1;
	}
	return (moved);
}



 bool	is_position_allowed(t_game_data *data, double x, double y)
{
	if (is_position_inside_map(data, x, y))
		return (true);
	if (is_position_free_of_walls(data, x, y))
		return (true);
	return (false);
}


bool	is_position_inside_map(t_game_data *data, double x, double y)
{
	if (x < 0.25 || x >= data->mapinfo.width - 1.25)
		return (false);
	if (y < 0.25 || y >= data->mapinfo.height -0.25)
		return (false);
	return (true);
}



 bool	is_position_free_of_walls(t_data *data, double x, double y)
{
	if (data->map[(int)y][(int)x] == '0')
		return (true);
	return (false);
}


