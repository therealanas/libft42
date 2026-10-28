/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <ahoumdi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 13:49:39 by username          #+#    #+#             */
/*   Updated: 2026/10/28 13:50:53 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

unsigned int	ft_lstsize(t_list *lst)
{
	unsigned int	l = 1;

	if (lst == NULL)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst->next;
		l++;
	}
	return (l);
}
