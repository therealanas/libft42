/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <ahoumdi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 13:48:45 by username          #+#    #+#             */
/*   Updated: 2026/11/01 14:41:15 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_countd(long n)
{
	long	r;

	r = 1;
	while (n >= 10)
	{
		n /= 10;
		r++;
	}
	return (r);
}

char	*ft_itoa(int n)
{
	long	s;
	long	num;
	long	l;
	char	*str;

	s = (n < 0);
	num = (long) n;
	if (s)
		num *= -1;
	l = ft_countd(num);
	str = malloc(l + s + 1);
	if (str == NULL)
		return (NULL);
	if (s == 1)
		l++;
	str[l--] = '\0';
	while (l >= s)
	{
		str[l--] = '0' + (num % 10);
		num /= 10;
	}
	if (s == 1)
		str[l] = '-';
	return (str);
}
