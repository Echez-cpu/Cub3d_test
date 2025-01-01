/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:37:31 by junhhong          #+#    #+#             */
/*   Updated: 2025/01/01 16:48:52 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static char	*decode_texture_path(char *line, int j)
{
	int		len;
	int		i;
	char	*path;

	while (line[j] && (line[j] == ' ' || line[j] == '\t'))
		j++;
	len = j;
	while (line[len] && (line[len] != ' ' && line[len] != '\t'))
		len++;
	path = malloc(sizeof(char) * (len - j + 1));
	if (!path)
		return (NULL);
	i = 0;
	while (line[j] && (line[j] != ' ' && line[j] != '\t' && line[j] != '\n'))
		path[i++] = line[j++];
	path[i] = '\0';
	while (line[j] && (line[j] == ' ' || line[j] == '\t'))
		j++;
	if (line[j] && line[j] != '\n')
	{
		free(path);
		path = NULL;
	}
	return (path);
}

static int	map_direction_to_texture(t_texinfo *textures, char *line, int j)
{
	if (line[j + 2] && ft_isprint(line[j + 2]))
		return (ERROR);
	if (line[j] == 'N' && line[j + 1] == 'O' && !(textures->north))
		textures->north = decode_texture_path(line, j + 2);
	else if (line[j] == 'S' && line[j + 1] == 'O' && !(textures->south))
		textures->south = decode_texture_path(line, j + 2);
	else if (line[j] == 'W' && line[j + 1] == 'E' && !(textures->west))
		textures->west = decode_texture_path(line, j + 2);
	else if (line[j] == 'E' && line[j + 1] == 'A' && !(textures->east))
		textures->east = decode_texture_path(line, j + 2);
	else
		return (ERROR);
	return (0);
}

static int	map_data_interpreter(t_game_data *data, char **map, int i, int j)
{
	while (map[i][j] == ' ' || map[i][j] == '\t' || map[i][j] == '\n')
		j++;
	if (ft_isprint(map[i][j]) && !ft_isdigit(map[i][j]))
	{
		if (map[i][j + 1] && ft_isprint(map[i][j + 1])
			&& !ft_isdigit(map[i][j]))
		{
			if (map_direction_to_texture(&data->texinfo, map[i], j) == ERROR)
				return (is_faulty("invalid texture\n"));
			return (BREAK);
		}
		else
		{
			if (set_floor_ceiling_colors(&data->texinfo, map[i], j) == ERROR)
				return (1);
			return (BREAK);
		}
	}
	else if (ft_isdigit(map[i][j]))
	{
		if (map_constructor(data, map, i) == FAIL)
			return (is_faulty("map description is wrong\n"));
		return (0);
	}
	return (CONTINUE);
}

int	extract_map_data(t_game_data *data, char **map)
{
	int	i;
	int	j;
	int	result;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			result = map_data_interpreter(data, map, i, j);
			if (result == BREAK)
				break ;
			else if (result == FAIL)
				return (1);
			else if (result == SUCCESS)
				return (0);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
