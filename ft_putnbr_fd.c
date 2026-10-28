/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <ahoumdi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 15:50:58 by username          #+#    #+#             */
/*   Updated: 2026/10/28 13:51:17 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	c = '0';
	int		r;

	if (n == INT_MIN)
	{
		r = -1 * (n % 10);
		n /= 10;
		ft_putnbr_fd(n, fd);
		ft_putnbr_fd(r, fd);
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
		ft_putnbr_fd(n, fd);
		return ;
	}
	else if (n >= 0 && n <= 9)
	{
		c += n;
		write(fd, &c, 1);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}
