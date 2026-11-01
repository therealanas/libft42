/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <ahoumdi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 19:02:36 by ahoumdi           #+#    #+#             */
/*   Updated: 2026/11/01 18:31:27 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*pd;
	const unsigned char	*ps;

	ps = (const unsigned char *) src;
	pd = (unsigned char *) dest;
	while (!(n-- <= 0))
		*(pd++) = *(ps++);
	return (dest);
}
