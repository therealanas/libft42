/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <ahoumdi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 09:44:14 by username          #+#    #+#             */
/*   Updated: 2026/10/28 13:51:09 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*ps;
	unsigned char		*pd;

	ps = (const unsigned char *) src;
	pd = (unsigned char *) dest;
	if (ps < pd)
	{
		while (!(n-- <= 0))
			*(pd + n) = (unsigned char) * (ps + n);
	}
	else
	{
		while (!(n-- <= 0))
			*(pd++) = (unsigned char) * (ps++);
	}
	return (dest);
}
