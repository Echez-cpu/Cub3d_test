

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




int	cleanup_resources(t_game_data *info)
{
	if (info->textures)
		free_things((void **)info->textures);
	if (info->texture_pixels)
		free_things((void **)info->texture_pixels);
	free_texinfo(&info->texinfo);
	free_map(info);
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
