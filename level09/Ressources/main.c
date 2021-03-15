# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdio.h>
# include <stdlib.h>

int		main(int ac, char **av)
{
	int			fd;
	struct stat	st;
	char		*src;

	fd = open(av[1], O_RDONLY);
	stat(av[1], &st);
	src = (char *)malloc(st.st_size);
	read(fd, src, st.st_size);
	close(fd);

	int i = 0;
	while (i < st.st_size)
	{
		src[i] = src[i] - i;
		i++;
	}
	puts(src);
	return (0);
}