/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <ahoumdi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:25:45 by ahoumdi           #+#    #+#             */
/*   Updated: 2026/11/02 13:41:48 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
