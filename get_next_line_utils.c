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

char	**checker(char **str)
{
	if (*str[0] == '\0')
	{
		free(*str);
		return (NULL);
	}
	return (str);
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
	size_t	p;
	size_t	i;

	i = 0;
	p = count * size;
	if ((p < count) || (p < size))
		return (NULL);
	memory = malloc(count * size);
	if (!memory)
		return (NULL);
	while (i < count * size)
		memory[i++] = '\0';
	return (memory);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *stash, char *buffer)
{
	char	*str;
	int		i;
	int		j;
	int		total;

	total = ft_strlen(stash) + ft_strlen(buffer);
	str = ft_calloc(sizeof(char), (total + 1));
	if (!str || !stash || !buffer)
		return (NULL);
	i = 0;
	while (stash[i])
	{
		str[i] = stash[i];
		i++;
	}
	j = 0;
	while (buffer[j])
	{
		str[i] = buffer[j];
		i++;
		j++;
	}
	free(stash);
	return (str);
}
