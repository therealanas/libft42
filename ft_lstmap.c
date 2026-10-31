/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 21:17:03 by ahoumdi           #+#    #+#             */
/*   Updated: 2026/10/30 17:59:50 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


t_list *ft_lstmap(t_list *lst, void *(*f)(void*),void (*del)(void *))
{
	t_list *new_head;
	t_list *new_lst;
	t_list *new_node;
	void *data;

	if (lst == NULL)
		return (NULL);
	data = f(lst->content);
	if (data == NULL)
		return (NULL);
	new_lst = ft_lstnew(data);
	if (new_lst == NULL)
	{
		del(data);
		return (NULL);
	}
	new_head = new_lst;
	lst = lst->next;
	while (lst != NULL)
	{
		data = f(lst->content);
	        if (data == NULL)
		{
			ft_lstclear(&new_head, del);
        	        return (NULL);
		}
		new_node = ft_lstnew(data);
		if (new_node == NULL)
		{	del(data);
			ft_lstclear(&new_head,del);
			return (NULL);
		}
		ft_lstadd_back(&new_head,new_node);
		lst=lst->next;
	}
	return (new_head);

}



