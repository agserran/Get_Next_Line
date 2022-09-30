/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agserran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:27:44 by agserran          #+#    #+#             */
/*   Updated: 2022/09/30 17:27:46 by agserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t size, size_t count)
{
	char	*memory;
	size_t	i;
	size_t	p;

	p = count * size;
	i = 0;
	if ((p < count) || (p < size))
		return (NULL);
	memory = malloc(count * size);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	c;
	size_t	c2;
	size_t	i;
	char	*memory;

	c = ft_strlen(s1);
	i = 0;
	c2 = ft_strlen(s2);
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	memory = ft_calloc(c + c2 + 1, sizeof(char));
	if (!memory)
		return (NULL);
	while (*s1 != 0)
	{
		memory[i] = s1[i];
		i++;
	}
	while (*s2 != 0)
	{
		memory[c] = *s2;
		c++;
		s2++;
	}
	return (memory);
}
