/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:32:48 by junhhong          #+#    #+#             */
/*   Updated: 2024/12/24 16:57:19 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"




size_t	find_max_row_width(t_mapinfo *map, int i)
{
	size_t	find_max_width;

	find_max_width = ft_strlen(map->file[i]);
	while (map->file[i])
	{
		if (ft_strlen(map->file[i]) > find_max_width)
			find_max_width = ft_strlen(map->file[i]);
		i++;
	}
	return (find_max_width);
}

