/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <ahoumdi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 22:04:26 by username          #+#    #+#             */
/*   Updated: 2026/10/28 13:51:11 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *p, int c, size_t n)
{
	unsigned char	val;
	unsigned char	*p2;

	val = (unsigned char) c;
	p2 = (unsigned char *) p;
	while (n-- > 0)
	{
		*(p2++) = val;
	}
	return (p);
}
