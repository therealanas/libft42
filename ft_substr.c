/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <ahoumdi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 15:08:34 by username          #+#    #+#             */
/*   Updated: 2026/10/28 13:36:22 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

static size_t	ft_strlen(char *s)
{
	size_t	l = 0;

	while (*(s++))
		l++;
	return (l);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i = 0;
	char	*r;
	size_t	l;

	if (s == NULL)
		return (NULL);
	l = ft_strlen((char *) s);
	r = malloc(len + 1);
	if (r == NULL)
		return (NULL);
	while ((i + start) < l && i < len)
	{
		r[i] = s[i + start];
		i++;
	}
	r[i] = '\0';
	return (r);
}
