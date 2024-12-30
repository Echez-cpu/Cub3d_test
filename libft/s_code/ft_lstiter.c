/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:11:27 by pokpalae          #+#    #+#             */
/*   Updated: 2024/12/30 16:21:23 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == ((void *)0) || f == ((void *)0))
	{
		return ;
	}
	while (lst != NULL)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
