
void	configure_textures(t_game_data *data)
{
	data->textures = ft_calloc(5, sizeof * data->textures);
	if (!data->textures)
		// clean and exit
	data->textures[NORTH] = xpm_to_img(data, data->texinfo.north);
	data->textures[SOUTH] = xpm_to_img(data, data->texinfo.south);
	data->textures[EAST] = xpm_to_img(data, data->texinfo.east);
	data->textures[WEST] = xpm_to_img(data, data->texinfo.west);
}