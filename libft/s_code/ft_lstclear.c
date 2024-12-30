/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:41:26 by pokpalae          #+#    #+#             */
/*   Updated: 2024/12/30 16:21:19 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	if (lst == ((void *)0) || del == NULL)
	{
		return ;
	}
	current = *lst;
	next = ((void *)0);
	while (current != NULL)
	{
		next = current->next;
		(*del)(current->content);
		free(current);
		current = next;
	}
	*lst = ((void *)0);
}
