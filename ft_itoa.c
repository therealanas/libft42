/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <ahoumdi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 15:16:19 by username          #+#    #+#             */
/*   Updated: 2026/10/28 13:50:38 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long	ft_countd(long n)
{
	long	r = 1;

	while (n >= 10)
	{
		n /= 10;
		r++;
	}
	return (r);
}

char	*ft_itoa(int n)
{
	long	s = 0;
	long	num = (long) n;
	long	l;
	char	*str;

	if (num < 0)
	{
		s = 1;
		num *= -1;
	}
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
