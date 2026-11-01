/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <ahoumdi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 13:47:33 by ahoumdi           #+#    #+#             */
/*   Updated: 2026/11/01 18:17:09 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*arr;
	unsigned char	*p;
	size_t			i;

	i = 0;
	if (size == 0 || nmemb == 0)
		return (malloc(1));
	if (size > (SIZE_MAX / nmemb))
		return (NULL);
	arr = malloc(nmemb * size);
	if (arr == NULL)
		return (NULL);
	p = arr;
	while (i < nmemb * size)
	{
		p[i] = 0;
		i++;
	}
	return (arr);
}
