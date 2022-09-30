/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agserran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:27:33 by agserran          #+#    #+#             */
/*   Updated: 2022/09/30 17:36:43 by agserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*stasher(int fd, char *stash)
{
	char	*buf;
	int		readd;

	readd = 1;
	if (!stash)
		stash = ft_calloc(sizeof(char), 1);
	buf = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!ft_strchr(buf, '\n') && readd != 0)
	{
		readd = read(fd, buf, BUFFER_SIZE);
		if (readd == -1)
		{
			free(buf);
			free(stash);
			return (NULL);
		}
		buf[readd] = '\0';
		stash = ft_strjoin(stash, buf);
	}
	free(buf);
	return (stash);
}

static char	*get_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	while (stash[i] != '\n')
		i++;
	line = (char *)ft_calloc(sizeof(char), i + 2);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] != '\n' && stash[i])
		line[i] = stash[i];
	return (line);
}

static char	*clearstash(char *stash)
{
	int		i;
	char	*memory;
	int		c;

	i = 0;
	c = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	memory = (char *) ft_calloc(sizeof(char), ft_strlen(stash) - i + 1);
	while (stash[i])
	{
		memory[c] = stash[i];
		i++;
		c++;
	}
	return (memory);
}

char	*get_next_line(int fd)
{
	static char	*stash[FD_SETSIZE];
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = stasher(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	buf = get_line(stash[fd]);
	stash[fd] = clearstash(stash[fd]);
	return (buf);
}

int main(void){

	int fd;
	fd = open("/Users/agserran/CURSUS/Get_Next_Line/Get_Next_Line/mifichero", O_RDONLY);
	printf("%s", get_next_line(fd));
	return 0;
}