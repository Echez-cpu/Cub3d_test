/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:27:58 by pokpalae          #+#    #+#             */
/*   Updated: 2024/12/30 16:22:49 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_help;
	const unsigned char	*s2_help;

	s1_help = s1;
	s2_help = s2;
	while (n > 0)
	{
		if (*s1_help != *s2_help)
		{
			return (*s1_help - *s2_help);
		}
		s1_help++;
		s2_help++;
		n--;
	}
	return (0);
}
