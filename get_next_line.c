#include "get_next_line.h"

char	*get_next_line(int fd)
{

}

int	main()
{
int	fd;
int	i;
char	*line;
char	*filename = "tests/test_text.txt";

fd = open(filename,  O_RDONLY);
if (fd == -1)
{
	perror("Error opening file");
	exit(1);
}
i = 1;
while (i < 100)
{
	line = get_next_line(fd);
	printf(" %s", line);
	free(line);
	i++;
}
close(fd);
}