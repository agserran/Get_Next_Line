#include "get_next_line.h"

char *get_next_line(int fd)
{
	char		*buf;
	static int	i;
	int			c;
	char		*linea;

	c = 0;
	i = 0;
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buf)
		return (NULL);
	if (fd == -1)
		return (NULL);
	else
		read(fd, buf, BUFFER_SIZE);
	if (*buf)
	{
		while (!ft_strchr(buf, '\n'))
			i++;
		linea = (char *)malloc(sizeof(char) * i + 1);
		while (c <= i)
		{
			linea[c] = buf[c];
			c++;
		}
	}
	return (linea);
}

int	main(void)
{
	int fd;

	fd = open("C:\\Users\\Intel Xeon\\Desktop\\cosas en c\\CURSUS\\gnl\miFichero", O_RDONLY);
	get_next_line(fd);
}