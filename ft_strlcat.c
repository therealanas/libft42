/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <ahoumdi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 15:45:41 by ahoumdi           #+#    #+#             */
/*   Updated: 2026/11/02 14:03:27 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ss;
	size_t	ds;
	size_t	i;

	ss = ft_strlen(src);
	ds = 0;
	i = 0;
	while (i < size && *(dst++))
	{
		ds++;
		i++;
	}
	if (size > 0)
		dst--;
	if (ds >= size)
		return (size + ss);
	if (size > 0)
	{
		while (i++ < size - 1 && (*src))
			*(dst++) = *(src++);
		*dst = '\0';
	}
	return (ds + ss);
}
