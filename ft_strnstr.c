/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <ahoumdi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 23:34:18 by username          #+#    #+#             */
/*   Updated: 2026/11/01 16:35:45 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[0] == '\0')
		return ((char *) big);
	while (i < len && big[i])
	{
		if (big[i] == little[j])
		{
			i++;
			j++;
			if (little[j] == '\0')
				return ((char *) &big[i - j]);
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	return (NULL);
}
