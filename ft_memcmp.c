/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <ahoumdi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 19:24:31 by ahoumdi           #+#    #+#             */
/*   Updated: 2026/11/01 18:30:49 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *) s1;
	p2 = (unsigned char *) s2;
	while (!(n-- <= 0))
	{
		if (*(p1++) != *(p2++))
			return (*(p1 - 1) - *(p2 - 1));
	}
	return (0);
}
