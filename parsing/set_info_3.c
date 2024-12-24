/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:37:31 by junhhong          #+#    #+#             */
/*   Updated: 2024/12/24 22:54:34 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

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
			result = ignore_whitespaces_get_info(data, map, i, j);
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