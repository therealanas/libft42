/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <ahoumdi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 14:53:44 by username          #+#    #+#             */
/*   Updated: 2026/10/28 13:51:58 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

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
	while (i <= l && &s[i] != NULL)
	{
		if ((unsigned char) s[i] == (unsigned char) c)
			return (char *)(&s[i]);
		i++;
	}
	return (NULL);
}
