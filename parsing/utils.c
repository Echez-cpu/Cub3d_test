/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:53:11 by junhhong          #+#    #+#             */
/*   Updated: 2024/12/30 15:15:11 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"


int is_faulty(char *str)
{
	ft_putstr_fd(str, 2);
	return (1);
}

int is_faulty_3(char *str)
{
	ft_putendl_fd(str, 2);
	return (2);
}

int is_faulty_2(char *str)
{
	ft_putendl_fd(str, 2);
	return (0);
}


int is_faulty_4(char *str)
{
	ft_putendl_fd(str, 2);
	return (errno);
}



int	end_game(t_game_data *data)
{
	exit_cleanly(data, 0);
	return (0);
}

