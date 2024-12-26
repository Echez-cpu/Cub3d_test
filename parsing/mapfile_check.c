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



int	verify_map_integrity(t_game_data *data, char **map_tab)
{ 
	if (!data->map)
		return (is_faulty("Error: map isn't present\n"));
	if (check_map_sides(&data->mapinfo, map_tab) == FAIL)
		return (is_faulty("Error: you lack surrounding walls\n"));
	if (data->mapinfo.height < 3)
		return (is_faulty("Error: map is not high enough\n"));
	if (check_map_elements(data, map_tab) == FAIL)
		return (FAIL);
	if (check_player_position(data, map_tab) == 1)
		return (FAIL);
	if (check_map_is_at_the_end(&data->mapinfo) == 1)
		return (is_faulty("Error: map is not last in the file\n"));
	return (0);
}


// add 'Error:' to the the full message 