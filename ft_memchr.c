#include "libft.h"
void    *ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *r = (unsigned char *)s;
	if (s == NULL || n == 0)
		return NULL;
	while (n > 0)
	{
	if (((unsigned char) *r == (unsigned char) c ) )
		return (r);
	r++;
	n--;
	}
	return (NULL);
}

