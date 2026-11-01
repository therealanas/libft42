/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <ahoumdi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 15:08:34 by ahoumdi           #+#    #+#             */
/*   Updated: 2026/11/01 18:49:39 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*r;
	size_t	l;
	size_t	size;

	i = 0;
	if (s == NULL)
		return (NULL);
	l = ft_strlen((char *) s);
	size = 0;
	if (start < l)
		size = l - start;
	if (len < size)
		size = len;
	r = malloc(size + 1);
	if (r == NULL)
		return (NULL);
	while ((i + start) < l && i < size)
	{
		r[i] = s[i + start];
		i++;
	}
	r[i] = '\0';
	return (r);
}
