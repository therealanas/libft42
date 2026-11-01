/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <ahoumdi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 13:51:49 by ahoumdi           #+#    #+#             */
/*   Updated: 2026/11/01 18:29:59 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*r;

	r = (unsigned char *) s;
	if (s == NULL || n == 0)
		return (NULL);
	while (n > 0)
	{
		if (((unsigned char)*r == (unsigned char) c))
			return (r);
		r++;
		n--;
	}
	return (NULL);
}
