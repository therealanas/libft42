/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: ahoumdi <ahoumdi@student.1337.ma>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/25 10:03:19 by ahoumdi          #+#    #+#              */
/*   Updated: 2026/11/01 18:39:39 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countsplits(char *s, char c, size_t l)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	if (l == 0)
		return (0);
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

static size_t	ft_strseplen(char *s, char c)
{
	size_t	l;

	l = 0;
	while (*s && *s != c)
	{
		l++;
		s++;
	}
	return (l);
}

static void	freeerr(char **s, size_t l)
{
	size_t	i;

	i = 0;
	while (i < l)
		free(s[i++]);
	free(s);
}

static char	*strsepcpy(char **s, char c)
{
	char	*r;
	char	*copy;
	size_t	l;

	while (**s == c)
		(*s)++;
	l = ft_strseplen(*s, c);
	r = malloc(l + 1);
	if (r == NULL)
		return (NULL);
	copy = r;
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
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	l = ft_strlen((char *) s);
	count = ft_countsplits((char *) s, c, l);
	p = malloc((count + 1) * sizeof(char *));
	if (p == NULL)
		return (NULL);
	while (i < count)
	{
		p[i] = strsepcpy((char **) & s, c);
		if (p[i] == NULL)
		{
			freeerr(p, i);
			return (NULL);
		}
		i++;
	}
	p[i] = NULL;
	return (p);
}
