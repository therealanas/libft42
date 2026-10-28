/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <ahoumdi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 11:16:38 by username          #+#    #+#             */
/*   Updated: 2026/10/28 13:52:06 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	r;
	size_t	sz;

	r = 0;
	sz = size;
	while ((size-- > 1) && *src)
	{
		*(dst++) = *(src++);
		r++;
	}
	while (*(src++))
		r++;
	if (sz > 0)
		*dst = '\0';
	return (r);
}
