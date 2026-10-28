/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <ahoumdi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 14:10:05 by username          #+#    #+#             */
/*   Updated: 2026/10/28 13:50:19 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*arr;
	unsigned char	*p;
	size_t			i = 0;
	size_t			fi = 0;

	if (size == 0 || nmemb == 0)
		return (NULL);
	if (size > (SIZE_MAX / nmemb))
		return (NULL);
	arr = malloc(nmemb * size);
	if (arr == NULL)
	{
		free(arr);
		return (NULL);
	}
	p = arr;
	while (i < nmemb * size)
	{
		p[i] = 0;
		i++;
	}
	return (arr);
}
