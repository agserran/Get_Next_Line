#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void *ft_calloc(size_t count, size_t size)
{
	char	*memory;
	size_t	i;
	size_t	p;

	p = count * size;
	i = 0;
	if ((p < count) ||(p < size))
		return (NULL);
	memory=malloc(count * size);
	if (!memory)
		return (NULL);
	ft_bzero(memory, count * size);
	return (memory);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}