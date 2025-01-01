/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:35:50 by junhhong          #+#    #+#             */
/*   Updated: 2025/01/01 16:46:35 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static int	assemble_map_grid(t_mapinfo *mapinfo, char **map_tab, int index)
{
	int	i;
	int	j;

	mapinfo->width = find_max_row_width(mapinfo, index);
	i = 0;
	while (i < mapinfo->height)
	{
		j = 0;
		map_tab[i] = malloc(sizeof(char) * (mapinfo->width + 1));
		if (!map_tab[i])
			return (is_faulty("memory allocation failed"));
		while (mapinfo->file[index][j] && mapinfo->file[index][j] != '\n')
		{
			map_tab[i][j] = mapinfo->file[index][j];
			j++;
		}
		while (j < mapinfo->width)
			map_tab[i][j++] = '\0';
		i++;
		index++;
	}
	map_tab[i] = NULL;
	return (0);
}

static int	calculate_map_height(t_game_data *data, char **file, int i)
{
	int	index_;
	int	j;

	index_ = i;
	while (file[i])
	{
		j = 0;
		while (file[i][j] == ' ' || file[i][j] == '\t' || file[i][j] == '\r'
			|| file[i][j] == '\v' || file[i][j] == '\f')
			j++;
		if (file[i][j] != '1')
			break ;
		i++;
	}
	data->mapinfo.end_of_map_index = i;
	return (i - index_);
}

static int	gather_map_metadata(t_game_data *data, char **file, int i)
{
	data->mapinfo.height = calculate_map_height(data, file, i);
	data->map = malloc(sizeof(char *) * (data->mapinfo.height + 1));
	if (!data->map)
		return (is_faulty("memory allocation failed"));
	if (assemble_map_grid(&data->mapinfo, data->map, i) == FAIL)
		return (1);
	return (0);
}

static void	map_spaces_into_walls(t_game_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] == ' ' || data->map[i][j] == '\t'
			|| data->map[i][j] == '\r' || data->map[i][j] == '\v'
			|| data->map[i][j] == '\f')
			j++;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == ' '
				&& j != data->map[i][ft_strlen(data->map[i]) - 1])
				data->map[i][j] = '1';
		}
		i++;
	}
}

int	map_constructor(t_game_data *data, char **file, int i)
{
	if (gather_map_metadata(data, file, i) == FAIL)
		return (1);
	map_spaces_into_walls(data);
	return (0);
}
