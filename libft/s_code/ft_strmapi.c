/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:59:01 by pokpalae          #+#    #+#             */
/*   Updated: 2024/12/30 16:23:36 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	unsigned int	i;
	char			*result_string;

	if (!s || !f)
		return ((void *)0);
	len = 0;
	while (s[len] != '\0')
		len++;
	result_string = (char *)malloc((len + 1) * sizeof(char));
	if (!result_string)
		return ((void *)0);
	i = 0;
	while (i < len)
	{
		result_string[i] = f(i, s[i]);
		i++;
	}
	result_string[len] = '\0';
	return (result_string);
}
