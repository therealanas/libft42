/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <ahoumdi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 23:34:18 by username          #+#    #+#             */
/*   Updated: 2026/10/28 13:52:12 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	fi;
	char	*p;

	i = 0;
	j = 0;
	fi = 0;
	p = NULL;
	if (little[0] == '\0')
		return ((char *) big);
	while (i < len && big[i])
	{
		if (little[j] == '\0')
			return (p);
		else if (big[i] == little[j])
		{
			if (j == 0)
			{
				p = (char *) & big[i];
				fi = i;
			}
			j++;
		}
		else
		{
			if (j > 0)
				i = fi + 1;
			else
				i++;
			continue ;
			j = 0 :
		}
		i++;
	}
	if (little[j] == '\0')
		return (p);
	return (NULL);
}
