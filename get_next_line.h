#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#ifndef	BUFFER_SIZE
#define BUFFER_SIZE 42

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);

# endif