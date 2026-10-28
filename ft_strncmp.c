/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <ahoumdi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:44:18 by username          #+#    #+#             */
/*   Updated: 2026/10/28 13:45:01 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i++ < n)
	{
		if ((unsigned char) * (s1++) != ((unsigned char) * (s2++)))
			return (((unsigned char) * (s1 - 1)) - (((unsigned char) * (s2 - 1))));
		else if (*(s1 - 1) == '\0' && *(s2 - 1) == '\0')
			return (0);
	}
	return (0);
}
