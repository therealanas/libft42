/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <ahoumdi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 10:03:19 by username          #+#    #+#             */
/*   Updated: 2026/10/28 13:51:55 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

size_t	ft_countsplits(char *s, char c, size_t l)
{
	int		count = 0;
	size_t	i = 0;

	while (i < l)
	{
		if (i != 0 && s[i] == c && s[i - 1] != c)
			count++;
		i++;
	}
	if (s[l - 1] != c)
		count++;
	return (count);
}

static size_t	ft_strlen(char *s)
{
	size_t	l = 0;

	while (*(s++))
		l++;
	return (l);
}

static size_t	ft_strseplen(char *s, char c)
{
	size_t	l = 0;

	while (*s && *s != c)
	{
		l++;
		s++;
	}
	return (l);
}

void	freeerr(char **s, size_t l)
{
	size_t	i = 0;

	while (i <= l)
		free(s[i++]);
	free(*s);
}

char	*strsepcpy(char **s, char c, size_t i)
{
	char	*r;
	char	*copy;
	size_t	l = ft_strseplen(*s, c);

	r = malloc(l + 1);
	if (r == NULL)
	{
		freeerr(&r, i);
		return (NULL);
	}
	copy = r;
	while (**s == c)
		(*s)++;
	while (**s && **s != c)
	{
		*(r++) = **(s);
		(*s)++;
	}
	*r = '\0';
	while (**s == c)
		(*s)++;
	return (copy);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	size_t	count;
	size_t	l;
	size_t	i = 0;

	if (s == NULL || *s == '\0')
	{
		if (s == NULL)
			p = NULL;
		else
		{
			p = malloc(sizeof(char *));
			if (p == NULL)
				return (NULL);
			p[0] = malloc(1);
			if (p[0] == NULL)
				return (NULL);
			p[0] = NULL;
		}
		return (p);
	}
	l = ft_strlen((char *) s);
	count = ft_countsplits((char *) s, c, l);
	p = malloc((count + 1) * sizeof(char *));
	if (p == NULL)
		return (NULL);
	while (i < count)
	{
		p[i] = strsepcpy((char **) & s, c, i);
		i++;
	}
	p[i] = NULL;
	return (p);
}
