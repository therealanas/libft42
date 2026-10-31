/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 18:20:30 by ahoumdi           #+#    #+#             */
/*   Updated: 2026/10/30 18:45:31 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstiter(t_list *lst,void (*f)(void*))
{
	if (lst == NULL)
		return ;
	while (lst != NULL )
	{
		f(lst->content);
		lst = lst->next;
	}
}
