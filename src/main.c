/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 03:26:32 by pokpalae          #+#    #+#             */
/*   Updated: 2025/01/01 17:15:50 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int argc, char **argv)
{
	t_game_data	info;

	if (argc != 2)
	{
		return (is_faulty("Error: Invalid number of arguments\n"));
	}
	setup_game_state(&info);
	if (validity_check(&info, argv) != 0)
		return (1);
	initialize_mlx(&info);
	configure_textures(&info);
	draw_graphics(&info);
	setup_input_hooks(&info);
	mlx_loop_hook(info.mlx, update_graphics, &info);
	mlx_loop(info.mlx);
	return (0);
}
