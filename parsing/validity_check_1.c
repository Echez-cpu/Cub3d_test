/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_check_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:17:45 by junhhong          #+#    #+#             */
/*   Updated: 2024/12/24 20:11:14 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../cub.h"

void exit_cleanly(t_game_data *info, int code)
{
	if (!info)
		exit(code);
	if (info->win && info->mlx)
		mlx_destroy_window(info->mlx, info->win);
	if (info->mlx)
	{
		mlx_destroy_display(info->mlx);
		mlx_loop_end(info->mlx);
		free(info->mlx);
	}
	cleanup_resources(info);
	exit(code);
}


 void	free_map(t_game_data *data)
{
	if (data->mapinfo.fd > 0)
		close(data->mapinfo.fd);
	if (data->mapinfo.file)
		free_things((void **)data->mapinfo.file);
	if (data->map)
		free_things((void **)data->map);
}



 int	validity_check(t_game_data *info, char **argv)
{
	if (set_fd(argv[1], true) == FAIL)
		exit_cleanly(info, 1);
	load_map_data(argv[1], info);
	if (get_file_data(info, info->mapinfo.file) == FAIL)
		return (free_data(info));
	if (check_map_validity(info, info->map) == FAIL)
		return (free_data(info));
	if (check_textures_validity(info, &info->texinfo) == FAIL)
		return (free_data(info));
	init_player_direction(info);
	// if (DEBUG_MSG)
	// 	debug_display_data(info);
	return (0);
}


