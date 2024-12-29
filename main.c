/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 03:26:32 by pokpalae          #+#    #+#             */
/*   Updated: 2024/12/27 03:26:37 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int argc, char **argv)
{
	t_game_data	info;

	if (argc != 2)
	{
		ft_putendl_fd("Error: Invalid number of arguments\n", 2);
		return (1);
	}
	if (validity_check(&info, argv) != 0) // change zero(0) to LIE
		return (1);

	  
 setup_game_state(&info);
 initialize_mlx(&info);
 configure_textures(&info);
 draw_graphics(&info);
 setup_input_hooks(&info);
//Performs the initial render of the game view.
//Casts rays for every column of pixels on the screen.
//Draws walls, ceilings, and floors based on the player’s current position and direction.
//The rendered image may be stored in an off-screen buffer.	
  
  //Sets up hooks or listeners for player input (e.g., keyboard or mouse events).
    
    mlx_loop_hook(info.mlx, update_graphics, &info);
	mlx_loop(info.mlx);
	return (0);
}
