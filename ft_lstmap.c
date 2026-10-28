/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 21:17:03 by ahoumdi           #+#    #+#             */
/*   Updated: 2026/10/28 22:50:19 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>


t_list *ft_lstmap(t_list *lst, void *(*f)(void*),void (*del)(void *))
{
	t_list *new_lst;
	t_list *old_head;
	
	if(lst == NULL)
		return;
	old_head = lst;
	new_lst = ft_lstnew(lst->content);
	new_head = new_lst;
	lst=lst->next;
	while(list != NULL)
	{ 
		ft_lstadd_back(&new_list,lst);
		new_lst->content = f(lst->content);
		lst=lst->next;

	}
	return(new_head);
}
