

#include "cub.h"

void	free_things(void **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

static void	destroy_map_data(t_game_data *data)
{
	if (data->mapinfo.fd > 0)
		close(data->mapinfo.fd);
	if (data->mapinfo.file)
		free_things((void **)data->mapinfo.file);
	if (data->map)
		free_things((void **)data->map);
}



int	cleanup_resources(t_game_data *info)
{
	if (info->textures)
		free_things((void **)info->textures);
	if (info->texture_pixels)
		free_things((void **)info->texture_pixels);
	cleanup_textures(&info->texinfo);
	destroy_map_data(info);
	return (1);
}



 void	cleanup_textures(t_texinfo *textures)
{
	if (textures->north)
		free(textures->north);
	if (textures->south)
		free(textures->south);
	if (textures->west)
		free(textures->west);
	if (textures->east)
		free(textures->east);
	if (textures->floor)
		free(textures->floor);
	if (textures->ceiling)
		free(textures->ceiling);
}



