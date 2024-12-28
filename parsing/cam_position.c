/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:13:06 by pokpalae          #+#    #+#             */
/*   Updated: 2024/12/24 16:58:14 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub.h"



int	is_white_space(char c)
{
	if (c != ' ' && c != '\t' && c != '\r'
		&& c != '\n' && c != '\v' && c != '\f')
		return (1);
	else
		return (SUCCESS);
}


 int	is_spawn_position_valid(t_game_data *data, char **map_grid)
{
	int	i;
	int	j;

	i = (int)data->first_person.pos_y;
	j = (int)data->first_person.pos_x;
	if (ft_strlen(map_grid[i - 1]) < (size_t)j
		|| ft_strlen(map_grid[i + 1]) < (size_t)j
		|| is_white_space(map_grid[i][j - 1]) == 0
		|| is_white_space(map_grid[i][j + 1]) == 0
		|| is_white_space(map_grid[i - 1][j]) == 0
		|| is_white_space(map_grid[i + 1][j]) == 0)
		return (FAIL);
	return (0);
}



 int	locate_cam_and_validate(t_game_data *data, char **map_grid)
{
	int	i;
	int	j;

	if (data->first_person.dir == '0')
		return(is_faulty("map has no starting position, use N, S, E, W\n"));
	i = 0;
	while (map_grid[i])
	{
		j = 0;
		while (map_grid[i][j])
		{
			if (ft_strchr("NSEW", map_grid[i][j]))
			{
				data->first_person.pos_x = (double)j + 0.5;
				data->first_person.pos_y = (double)i + 0.5;
				map_grid[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	if (is_spawn_position_valid(data, map_grid) == FAIL)
		return(is_faulty("invalid camera position\n"));
	return (0);
}


 int	ensure_no_data_after_map(t_mapinfo *map)
{
	int	i;
	int	j;

	i = map->end_of_map_index;
	while (map->file[i])
	{
		j = 0;
		while (map->file[i][j])
		{
			if (map->file[i][j] != ' ' && map->file[i][j] != '\t'
				&& map->file[i][j] != '\r' && map->file[i][j] != '\n'
				&& map->file[i][j] != '\v' && map->file[i][j] != '\f')
				return (FAIL);
			j++;
		}
		i++;
	}
	return (0);
}