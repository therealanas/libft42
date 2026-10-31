/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <ahoumdi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 20:15:00 by username          #+#    #+#             */
/*   Updated: 2026/10/30 19:39:09 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

static int	isin(char c, char *s)
{
	while (*s)
	{
		if ((unsigned char) * (s++) == (unsigned char) c)
			return (1);
	}
	return (0);
}

static size_t	ft_strlen(char *s)
{
	size_t	l = 0;

	while (*(s++))
		l++;
	return (l);
}

static size_t	getlast(size_t l, size_t suf, char *s, char *set)
{
	while (1)
	{
		if (!isin(s[l], (char *) set))
		{
			suf = l;
			break ;
		}
		if (l == 0)
			break ;
		l--;
	}
	return (suf);
}

static size_t	getfirst(size_t l, size_t pre, char *s, char *set)
{
	size_t	i = 0;

	while (i < l)
	{
		if (!isin(s[i], (char *) set))
		{
			pre = i;
			break ;
		}
		i++;
	}
	return (pre);
}

static char	*rempty(char *r)
{
	r = malloc(1);
	if (r == NULL)
		return (NULL);
	r[0] = '\0';
	return (r);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	l = 0;
	size_t	i = 0;
	size_t	prei = 0;
	size_t	sufi = 0;
	char	*r = NULL;

	if (s1 == NULL || set == NULL)
		return (NULL);
	l = ft_strlen((char *) s1);
	if (l == 0)
		return (rempty(r));
	sufi = getlast(l - 1, sufi, (char *) s1, (char *) set);
	prei = getfirst(l, prei, (char *) s1, (char *) set);
	if (sufi == 0 && isin(s1[0], (char *) set))
		return (rempty(r));
	r = malloc((sufi - prei) + 2);
	if (r == NULL)
		return (NULL);
	while (prei <= sufi && s1[prei])
		r[i++] = s1[prei++];
	r[i] = '\0';
	return (r);
}
