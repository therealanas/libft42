/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <ahoumdi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 13:52:18 by ahoumdi           #+#    #+#             */
/*   Updated: 2026/11/01 18:40:34 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ps;
	int		i;
	int		l;

	ps = (char *) s;
	i = 0;
	l = 0;
	while (*(ps++))
		l++;
	while (i <= l)
	{
		if ((unsigned char) s[i] == (unsigned char) c)
			return ((char *)(&s[i]));
		i++;
	}
	return (NULL);
}
