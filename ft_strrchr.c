/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <ahoumdi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:25:45 by username          #+#    #+#             */
/*   Updated: 2026/10/28 13:52:09 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*ps;
	char	*pr;
	int		i;
	int		l;

	ps = (char *) s;
	pr = NULL;
	i = 0;
	l = 0;
	while (*(ps++))
		l++;
	while (i <= l && &s[i] != NULL)
	{
		if ((unsigned char) s[i] == (unsigned char) c)
			pr = (char *)(&s[i]);
		i++;
	}
	return (pr);
}
