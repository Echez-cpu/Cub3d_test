/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:49:56 by pokpalae          #+#    #+#             */
/*   Updated: 2024/12/30 16:22:52 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*destination;
	const unsigned char	*source;

	if (dst == ((void *)0) && src == ((void *)0))
	{
		return ((void *)0);
	}
	destination = dst;
	source = src;
	while (n > 0)
	{
		*destination = *source;
		destination++;
		source++;
		n--;
	}
	return (dst);
}
