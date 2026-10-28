/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <ahoumdi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 15:45:41 by username          #+#    #+#             */
/*   Updated: 2026/10/28 13:52:04 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ss;
	size_t	ds;
	size_t	i;
	char	*ps;

	ss = 0;
	ds = 0;
	i = 0;
	ps = (char *) src;
	while (i < size && *(dst++))
	{
		ds++;
		i++;
	}
	dst--;
	while (*(ps++))
		ss++;
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
