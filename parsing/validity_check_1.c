/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_check_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:17:45 by junhhong          #+#    #+#             */
/*   Updated: 2025/01/01 16:43:20 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	exit_cleanly(t_game_data *info, int code)
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
	if (extract_map_data(info, info->mapinfo.file) == FAIL)
		return (cleanup_resources(info));
	if (verify_map_integrity(info, info->map) == FAIL)
		return (cleanup_resources(info));
	if (validate_game_assets(&info->texinfo) == FAIL)
		return (cleanup_resources(info));
	init_camera_angles(info);
	return (0);
}
