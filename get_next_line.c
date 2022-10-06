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
	int		readed;

	readed = 1;
	if (!stash)
		stash = ft_calloc(sizeof(char), 1);
	//printf("Stash arriba <%s>", stash);
	buf = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!ft_strchr(buf, '\n') && readed != 0) {
		readed = read(fd, buf, BUFFER_SIZE);
		//printf("Readed -> %d\n", readed);
		if (readed == -1) {
			free(buf);
			free(stash);
			return (NULL);
		}
		buf[readed] = '\0';
		//printf("Buf: [%s]\n", buf);
		stash = ft_strjoin(stash, buf);
		//printf("Stash: [%s]\n", stash);
	}
	//printf("Stash [%s]", stash);
	free(buf);
	if (stash[0] == '\0')
	{
		free(stash);
		return(NULL);
	}
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
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n' && stash[i])
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
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	memory = (char *) ft_calloc(sizeof(char), ft_strlen(stash) - i + 1);
	if (!memory)
		return (NULL);
	i++;
	while (stash[i])
	{
		memory[c] = stash[i];
		i++;
		c++;
	}
	free(stash);
	return (memory);
}

char	*get_next_line(int fd)
{
	static char	*stash[FD_SETSIZE];
	char		*buf;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = stasher(fd, stash[fd]);
	//printf("%s", stash[fd]);
	if (!stash[fd])
		return (NULL);
	buf = get_line(stash[fd]);
	stash[fd] = clearstash(stash[fd]);

	return (buf);
}

//int main(void){
//
//	int fd;
//	char *line;
//
//	//fd = open("./gnlTester/files/empty", O_RDONLY);
//	fd = open("./mifichero", O_RDONLY);
////	while (line)
////	{
////		line = get_next_line(fd);
////		if (line != NULL)
////			printf("%s", line);
////		free(line);
////	}
//
//	line = get_next_line(fd);
//	printf("%s", line);
//	free(line);
//	close(fd);
//	//system("leaks a.out");
//
//	return 0;
//}
