/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:02:32 by junhhong          #+#    #+#             */
/*   Updated: 2024/12/24 17:03:51 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static int	ensure_row_is_wall(char **map_grid, int i, int j)
{
	if (!map_grid || !map_grid[i] || !map_grid[i][j])
		return (FAIL);
	while (map_grid[i][j] == ' ' || map_grid[i][j] == '\t'
	|| map_grid[i][j] == '\r' || map_grid[i][j] == '\v'
	|| map_grid[i][j] == '\f')
		j++;
	while (map_grid[i][j])
	{
		if (map_grid[i][j] != '1')
			return (FAIL);
		j++;
	}
	return (0);
}



int	confirm_map_enclosure(t_mapinfo *map, char **map_grid)
{
	int	i;
	int	j;

	if (ensure_row_is_wall(map_grid, 0, 0) == FAIL)
		return (FAIL);
	i = 1;
	while (i < (map->height - 1))
	{
		j = ft_strlen(map_grid[i]) - 1;
		if (map_grid[i][j] != '1')
			return (FAIL);
		i++;
	}
	if (ensure_row_is_wall(map_grid, i, 0) == FAIL)
		return (1);
	return (0);
}


 int	inspect_map_characters(t_game_data *data, char **map_grid)
{
	int	i;
	int	j;

	i = 0;
	data->first_person.dir = '0';
	while (map_grid[i] != NULL)
	{
		j = 0;
		while (map_grid[i][j])
		{
			while (data->map[i][j] == ' ' || data->map[i][j] == '\t'
			|| data->map[i][j] == '\r'
			|| data->map[i][j] == '\v' || data->map[i][j] == '\f')
				j++;
			if (!(ft_strchr("10NSEW", map_grid[i][j])))
				return(is_faulty("an invalid character is found in the map\n"));
			if (ft_strchr("NSEW", map_grid[i][j]) && data->first_person.dir != '0')
				return(is_faulty("map has more than one starting position\n"));
			if (ft_strchr("NSEW", map_grid[i][j]) && data->first_person.dir == '0')
				data->first_person.dir = map_grid[i][j];
			j++;
		}
		i++;
	}
	return (0);
}



int	verify_map_integrity(t_game_data *data, char **map_grid)
{ 
	if (!data->map)
		return (is_faulty("Error: map isn't present\n"));
	if (confirm_map_enclosure(&data->mapinfo, map_grid) == FAIL)
		return (is_faulty("Error: you lack surrounding walls\n"));
	if (data->mapinfo.height < 3)
		return (is_faulty("Error: map is not high enough\n"));
	if (inspect_map_characters(data, map_grid) == FAIL)
		return(FAIL);
	if (locate_cam_and_validate(data, map_grid) == 1)
		return (FAIL);
	if (ensure_no_data_after_map(&data->mapinfo) == 1)
		return (is_faulty("Error: map is not last in the file\n"));
	return (0);
}


