/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <ahoumdi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 15:34:47 by username          #+#    #+#             */
/*   Updated: 2026/10/30 19:53:28 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *current;
	t_list *next;

	if (lst == NULL)
		return;
	if (*lst == NULL)
		return;

	current = *lst;
	while (current != NULL)
	{
		next= current->next;
		del(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
}




