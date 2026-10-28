/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <ahoumdi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 15:55:38 by username          #+#    #+#             */
/*   Updated: 2026/10/28 13:52:00 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*p = (char *) s;
	char	*r;

	while (*(p++))
		;
	r = malloc(p - s);
	if (r == NULL)
	{
		return (NULL);
	}
	p = r;
	while (*s)
	{
		*r = (char)*s;
		r++;
		s++;
	}
	*r = '\0';
	return (p);
}
