/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <ahoumdi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 19:39:24 by username          #+#    #+#             */
/*   Updated: 2026/11/01 17:23:44 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	size_t	l1;
	size_t	l2;
	size_t	i;

	i = 0;
	if (s2 == NULL || s1 == NULL)
		return (NULL);
	l1 = ft_strlen((char *) s1);
	l2 = ft_strlen((char *) s2);
	r = malloc(l1 + l2 + 1);
	if (r == NULL)
		return (NULL);
	while (i < l1)
		*(r++) = s1[i++];
	i = 0;
	while (i < l2)
		*(r++) = s2[i++];
	*r = '\0';
	return (r - (l1 + l2));
}
