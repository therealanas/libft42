/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <ahoumdi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:35:42 by username          #+#    #+#             */
/*   Updated: 2026/10/28 13:49:44 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

static int	checkmax(char s, int sum)
{
	if (sum == 214748364)
	{
		if (s == '8')
			return (1);
	}
	return (0);
}

int	ft_atoi(const char *ptr)
{
	int	sum;
	int	s;

	sum = 0;
	s = 1;
	int	i = 0;

	while (ptr[i] == 32 || (ptr[i] >= 9 && ptr[i] <= 13))
		i++;
	if (ptr[i] == '-' || ptr[i] == '+')
	{
		if (ptr[i] == '-')
			s *= -1;
		i++;
	}
	while (ptr[i] >= '0' && ptr[i] <= '9')
	{
		if (checkmax(ptr[i], sum))
			return (INT_MIN);
		sum *= 10;
		sum += ptr[i] - '0';
		i++;
	}
	if (s == 1)
		return (sum);
	return (-sum);
}
